#include <iostream>
#include <fstream>
#include <cstdlib>
#include "To_do_list.h"

//////////////Fonctions relatives à Task///////////

void Task :: change_title(){
    std::cout<<"Nouveau titre:";
    std::string new_title="";
    std::cin>>new_title;
    title = new_title;
}
void Task :: change_description(){
    std::cout<<"Nouvelle description:";
    std::string new_description="";
    std::cin>>new_description;
    description=new_description;
}
void Task :: change_commentary(){
    std::cout<<"Nouveau commentaire:";
    std::string new_commentary="";
    std::cin>>new_commentary;
    commentary=new_commentary;
}
void Task :: change_percent(){
    std::cout<<"Nouveau pourcentage(entre 0 et 100):";
    std::string new_percent;
    std::cin>>new_percent;
    percent=new_percent;
}
void Task :: change_priority(){
    std::cout<<"0.Priorité faible  1.Prioritaire"<<std::endl;
    int choix_prio=0;
    std::cin>>choix_prio;
    if(choix_prio==0){priority="faible";}
    else if(choix_prio==1){priority="prioritaire";}
    else{std::cout<<"Choix non reconnu. Recommencez"<<std::endl; 
        change_priority();}    
}

void Task::change_closing_date(){
    std::cout<<"Nouvelle date de cloture:";
    std::string new_closing_date;
    std::cin>>new_closing_date;
    closing_date=new_closing_date;
}
void Task :: add_subtask(){//On ne va que demander un titre, un pourcentage, et une date de cloture pour les sous-taches
    std::cout<<"------Menu d'ajout de sous tache-------"<<std::endl;
    std::string sub_title;
    std::string pourcentage_sub;
    std::string date_cloture_sub;
    std::cout<<"Titre de la sous-tache:";
    std::cin>>sub_title;
    std::cout<<""<<std::endl;
    std::cout<<"Pourcentage de la sous-tache:";
    std::cin>>pourcentage_sub;
    std::cout<<""<<std::endl;
    std::cout<<"Date de cloture de la sous-tache:";
    std::cin>>date_cloture_sub;
    std::cout<<""<<std::endl;
    Task* new_ad_subtask=new Task(0,sub_title,"","",pourcentage_sub,"","",date_cloture_sub);
    sub_task.push_back(new_ad_subtask);
    std::cout<<"Ajout de sous tache confirmé"<<std::endl;
} 

void Task::print_sub_task(Task* ad_sub_task){
    std::cout<<"    -"<<ad_sub_task->title<<", "<<ad_sub_task->percent<<"%, "<<ad_sub_task->closing_date<<std::endl;
}
void Task::print_title(){ // utilisé seulement pour print_list_task
    std::cout<<". Titre : "<<title<<std::endl;
}
void Task::print(){
    std::cout<<"Titre : "<<title<<std::endl;
    std::cout<<"Description : "<<description<<std::endl; 
    std::cout<<"Status : "<<status<<std::endl; 
    std::cout<<"Priorité : "<<priority<<std::endl; 
    std::cout<<"Commentaire : "<<commentary<<std::endl; 
    std::cout<<"Pourcentage : "<<percent<<"%"<<std::endl;
    std::cout<<"Date fermeture :"<<closing_date<<std::endl;
    std::cout<<"Sous-taches : "<<std::endl;  
    for(auto e :sub_task){
        print_sub_task(e);
        std::cout<<""<<std::endl;//pour rajouter une ligne blanche entre chaque sous-taches
        };

}


void Task :: close_task(){ //On ne change pas la date de cloture, car celle ci sera décidée par l'utilisateur
     status="fermé";
}
void Task :: activate_task(){
    status="ouvert";
}

 //////////////Fonctions relatives à Taskmanager ///////////
void Task_manager::modify_task(int n){
    Task* selected_ad_task=vect_ad_tache[n];
    std::cout<<"-----Menu de modification-----"<<std::endl;
    std::cout<<"0.Revenir au menu précedent"<<std::endl;
    std::cout<<"1.Changer le titre"<<std::endl;
    std::cout<<"2.Changer la description"<<std::endl;
    std::cout<<"3.Changer le commentaire"<<std::endl;
    std::cout<<"4.Changer la priorité"<<std::endl;
    std::cout<<"5.Changer le pourcentage"<<std::endl;
    std::cout<<"6.Changer la date de cloture"<<std::endl;
    std::cout<<"7.Ajouter une sous-tache"<<std::endl;
    int choix=0;
    std::cin>>choix;
    if(choix==0){select_task(n);}
    else if(choix==1){selected_ad_task->change_title();
                    std::cout<<"Changement confirmé"<<std::endl;
                    modify_task(n);}
    else if(choix==2){selected_ad_task->change_description();
                    std::cout<<"Changement confirmé"<<std::endl;
                    modify_task(n);}
    else if(choix==3){selected_ad_task->change_commentary();
                    std::cout<<"Changement confirmé"<<std::endl;
                    modify_task(n);}
    else if(choix==4){selected_ad_task->change_priority();
                    std::cout<<"Changement confirmé"<<std::endl;
                    modify_task(n);}
    else if(choix==5){selected_ad_task->change_percent();
                    std::cout<<"Changement confirmé"<<std::endl;
                    modify_task(n);}
    else if(choix==6){selected_ad_task->change_closing_date();
                    std::cout<<"Changement confirmé"<<std::endl;
                    modify_task(n);}
    else if(choix==7){
        selected_ad_task->add_subtask();
        modify_task(n);
        }
    else{std::cout<<"Choix non reconnu. Recommencez"<<std::endl;
        modify_task(n);}
}

void Task_manager::select_task(int n){
        Task* selected_ad_task=vect_ad_tache[n];
        std::cout<<"-------Menu de tache--------"<<std::endl;
        std::cout<<"La tache sélectionnée est la suivante :"<<std::endl;
        selected_ad_task->print();
        std::cout<<""<<std::endl;//pour passer une ligne (et être ainsi plus visible)
        std::cout<<"Choisissez une des options suivantes"<<std::endl;
        std::cout<<"0.Revenir au menu precedent"<<std::endl;
        std::cout<<"1.Modifier la tache selectionnée"<<std::endl;
        std::cout<<"2.Fermer la tache (celle ci apparaitra encore dans la liste)"<<std::endl;
        std::cout<<"3.Activer la tache"<<std::endl;
        int num=0;
        std::cin>>num;
        if(num==0){print_task_list();}
        else if(num==1){modify_task(n);}
        else if(num==2){selected_ad_task->close_task();
                        init();}
        else if(num==3){selected_ad_task->activate_task();
                        select_task(n);}
        else{std::cout<<"Choix non reconnu. Recommencez"<<std::endl;
        select_task(n);}
        
}


void Task_manager::print_task_list(){
    std::cout<<"---------------Liste des taches------------"<<std::endl;
    if (nbr==0){std::cout<<"Pas de tache dans la liste. Retour au menu principal"<<std::endl;//cas vect_task vide
    init();}
    else{int n=1;
    for(auto e:vect_ad_tache){
       std::cout<<n;
       e->print_title();
       n=n+1;
       std::cout<<""<<std::endl;
    }
    int num=0;
    std::cout<<"Selectionnez une tache , ou revenez au menu precedent en entrant 0"<<std::endl;
    std::cin>>num;
    if(num==0){init();}
    else if(num>0 && num<=nbr){
        select_task(num-1);
    }
    else{std::cout<<"Choix non reconnu. Recommencez"<<std::endl;
    print_task_list();}
}
}

std::string Task_manager::ask_priority(){
    int num_prio=0;
    std::cout<<"0.Priorité faible   1.Prioritaire "<<std::endl;
    std::cin>>num_prio;
    std::cout<<""<<std::endl;
    if(num_prio==0){return "faible";}
    else if(num_prio==1){return "prioritaire";}
    else{std::cout<<"choix non reconnu, recommencez"<<std::endl;
    ask_priority();
    return "";}
    }
    
std::string Task_manager::ask_status(){
    int num_stat=0;
    std::cout<<"0.Fermé  1.Ouvert "<<std::endl;
    std::cin>>num_stat;
    std::cout<<""<<std::endl;
    if(num_stat==0){return "faible";}
    else if(num_stat==1){return "ouvert";}
    else{std::cout<<"choix non reconnu, recommencez"<<std::endl;
    ask_status();
    return "";}
    }

void Task_manager::save_task(){
    std::ofstream fichier("Save_list.txt");
    if (fichier){
        fichier.seekp(0,std::ios::beg);//on se place au debut
        for (auto e:vect_ad_tache){//on sauvegarde toutes les taches en une seule fois
            int len=(e->sub_task).size();//pour ajouter et lire les sous_taches, il nous faudra leur nombre
            fichier<<len<<std::endl;
            fichier<<e->title<<std::endl;
            fichier<<e->description<<std::endl;
            fichier<<e->status<<std::endl;
            fichier<<e->percent<<std::endl;
            fichier<<e->priority<<std::endl;
            fichier<<e->commentary<<std::endl;
            fichier<<e->closing_date<<std::endl;
            for(auto sous_tache:e->sub_task){//pour toutes les sous-taches dans la tache
                fichier<<sous_tache->title<<std::endl;
                fichier<<sous_tache->percent<<std::endl;
                fichier<<sous_tache->closing_date<<std::endl;
            }
        }
}
    else{std::cout<<"ERREUR, impossible d'acceder au fichier de sauvegarde"<<std::endl;}
}

void Task_manager::add_task(){
    std::cout<<"-------------Menu d'ajout de tache--------------"<<std::endl;
    std::string titre="";
    std::string desc="";
    std::string com="";
    std::string stat="";
    std::string priorit="";
    std::cout<<"Ne pas mettre d'espace dans les champs"<<std::endl;
    std::cout<<"Titre :";
    std::cin>>titre;
    std::cout<<""<<std::endl;
    std::cout<<"Description :";
    std::cin>>desc;
    std::cout<<""<<std::endl;
    std::cout<<"Commentaire :";
    std::cin>>com;
    std::cout<<""<<std::endl;
    priorit=ask_priority();
    stat=ask_status();
    std::string percent;
    std::cout<<"Pourcentage :";
    std::cin>>percent;
    std::cout<<""<<std::endl;
    std::string date_cloture;
    std::cout<<"Date de cloture (format dd/mm/aaaa) :";
    std::cin>>date_cloture;
    std::cout<<""<<std::endl;
    int id=0;//à trouver après en lisant fichier texte
    Task* ad_new_task= new Task(id,titre,desc, stat,percent,priorit,com,date_cloture);
    std::cout<<"Voulez vous ajouter cette tache au TaskManager?"<<std::endl;
    std::cout<<"0.Non      1.Oui"<<std::endl;
    ad_new_task->print();
    int choix=0;
    std::cin>>choix;
    if(choix==0){
        std::cout<<"Ajout de tache annulé, retour au menu principal"<<std::endl;
        init();
        }
    else{
        vect_ad_tache.push_back(ad_new_task);
        nbr++;
        std::cout<<"ajout de tache confirmé"<<std::endl;
        std::cout<<"l'ajout de sous-tache se fait dans la partie modification"<<std::endl;
        init();
        }
}





void Task_manager::reinit_task_manager(){
    std::cout<<"cette fonction n'est pas encore disponible"<<std::endl;
    std::cout<<"retour au menu principal"<<std::endl;
    init();
}
void Task_manager::read_save_file(){
    std::ifstream fichier("Save_list.txt");
    if(fichier){
        fichier.seekg(0,std::ios::beg);
        int numero_ligne=0;
        int numero_tache=0;
        int nbr_sous_tache=0;
        std::string title;
        std::string description;
        std::string status;
        std::string percent;
        std::string priority;
        std::string commentary;
        std::string date_cloture;
        std::string ligne;
        while(std::getline(fichier,ligne)){
            int id=numero_tache;
            if(numero_ligne==0){nbr_sous_tache=std::atoi(ligne.c_str());numero_ligne++;}
            else if(numero_ligne==1){title=ligne;numero_ligne++;}
            else if(numero_ligne==2){description=ligne;numero_ligne++;}
            else if(numero_ligne==3){status=ligne;numero_ligne++;}
            else if(numero_ligne==4){percent=ligne;numero_ligne++;}
            else if(numero_ligne==5){priority=ligne;numero_ligne++;}
            else if(numero_ligne==6){commentary=ligne;numero_ligne++;}
            else if(numero_ligne==7 && nbr_sous_tache==0){
                date_cloture=ligne;
                Task* new_ad_task=new Task(id,title,description,status,percent,priority,commentary,date_cloture);
                vect_ad_tache.push_back(new_ad_task);
                nbr++;
                numero_ligne=0;
                numero_tache++;
                }
            else if(numero_ligne==7 && nbr_sous_tache!=0){
                date_cloture=ligne;
                Task* new_ad_task=new Task(id,title,description,status,percent,priority,commentary,date_cloture);
                numero_ligne++;
                std::getline(fichier,ligne);
                std::vector<Task*> vect_sub_task;
                for(int i=0;i<=nbr_sous_tache;i++){
                   std::string sub_title;
                    std::string sub_percent;
                    std::string sub_closing_date;
                   while(numero_ligne-i<=10){
                    
                    if(numero_ligne==8+i){
                        sub_title=ligne;
                        numero_ligne++;
                        std::getline(fichier,ligne);
                        }
                    else if(numero_ligne==9+i){
                        sub_percent=ligne;
                        numero_ligne++;
                        std::getline(fichier,ligne);
                        }
                    else if(numero_ligne==10+i){
                        
                        sub_closing_date=ligne;
                        numero_ligne++;
                        std::getline(fichier,ligne);
                        }
                    }
                    Task* new_ad_sub_task=new Task(0,sub_title,"","",sub_percent,"","",sub_closing_date);
                    vect_sub_task.push_back(new_ad_sub_task);
                }
                new_ad_task->sub_task=vect_sub_task;
                vect_ad_tache.push_back(new_ad_task);
                nbr++;
                numero_ligne=0;
                numero_tache++;
            }

        }

    }
    else{
        std::cout<<"ERREUR: Impossible d'ouvrir ficher de sauvegarde"<<std::endl;
    }
    init();
}

void Task_manager::init(){
     std::cout<<"----------------Menu du TaskManager---------------"<<std::endl;
     std::cout<<"0.Quitter"<<std::endl;
     std::cout<<"1.Liste des taches"<<std::endl; 
     std::cout<<"2.Ajouter une tache"<<std::endl;
     std::cout<<"3.Réinitialiser le TaskManager"<<std::endl;
     int num=0;
     std::cin>>num;
     if(num==0){save_task();//on sauvegarde toutes les taches présentes dans le vecteur
        std::cout<<"Quitting..."<<std::endl;}
     else if(num==1){print_task_list();}
     else if(num==2){add_task();}
     else if(num==3){reinit_task_manager();}
     else{std::cout<<"Choix non reconnu. Recommencez"<<std::endl;
     init();}

 }




 int main(){
    Task_manager toto;
    toto.read_save_file();
 }