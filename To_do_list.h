#include <iostream>
#include <string>
#include <vector>
#include <exception>
#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

class OrderError:public std::runtime_error{ //exeption pour finir nn utilisé
    public:
    OrderError(const char* msg) noexcept: std::runtime_error(msg){}
};

class Task{
    friend class Task_manager;
    protected:
    int id;//l'id peut changer dnas le cas d'une suppression d'une tache intermediaire
    std::string closing_date;//à l'utilisateur de définir la date de fin de la tache
    std::string percent;//plus facile d'en faire une chaine de caractères pour la lecture du fichier. Je n'ai trouvé que bine plus tard la fct stoi
    std::string title;
    std::string description;
    std::string status;//ouvert ou fermé
    std::string priority;//faible ou prioritaire
    std::string commentary;
    std::vector<Task*> sub_task;
    public:
    Task(int ID,std::string titre,std::string des, std::string stat, std::string percentage, std::string prio ,std::string comment,std::string date_cloture ): 
        id(ID), title(titre), description(des),status(stat), percent(percentage), priority(prio), commentary(comment), closing_date(date_cloture){}
    //j'ai pas mis de destructeur, parce que il n'y a pas de new dans le constructeur, donc je savais pas si il en fallait un ou pas.

    void change_title();
    void change_description();
    void change_priority();
    void change_commentary();
    void change_percent();
    void change_closing_date();
    void add_subtask();
    void close_task();
    void activate_task();
    void print();
    void print_sub_task(Task* ad_sub_task);//un peu différent de print, on ne fera qu'apparaitre les titres
    void print_title();
};

class Task_manager{
    protected:
    int nbr;//nombre de tache dnas le task_manager
    std::vector<Task*> vect_ad_tache;
    public:
    Task_manager():nbr(0){};
    //pareil pas de destructeur
    void read_save_file();
    void init();
    void save_task();
    void print_task_list();
    void add_task();
    std::string ask_priority();//utilisé pour add_task. Permet de limiter proprement les choix possibles
    std::string ask_status();//utilisé pour add_task. Permet de limiter proprement les choix possibles
    void select_task(int n);
    void reinit_task_manager();//supprime toutes les taches du task_manager
    void modify_task(int n);
    void remove_task(int n);
    void delete_sub_task(int n);
};

#endif//
