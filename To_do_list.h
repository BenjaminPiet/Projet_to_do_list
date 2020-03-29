#include <iostream>
#include <string>
#include <vector>
#include <exception>
#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

class OrderError:public std::runtime_error{
    public:
    OrderError(const char* msg) noexcept: std::runtime_error(msg){}
};

class Task{
    friend class Task_manager;
    protected:
    int id;//
    std::string closing_date;//à l'utilisateur de définir la date de fin de la tache
    std::string percent;//plus facile d'en faire une chaine de caractères pour la lecture du fichier
    std::string title;
    std::string description;
    std::string status;//ouvert ou fermé
    std::string priority;//faible ou prioritaire
    std::string commentary;
    std::vector<Task*> sub_task;
    public:
    Task(int ID,std::string titre,std::string des, std::string stat, std::string percentage, std::string prio ,std::string comment,std::string date_cloture ): 
        id(ID), title(titre), description(des),status(stat), percent(percentage), priority(prio), commentary(comment), closing_date(date_cloture){}


    void change_title();
    void change_description();
    void change_priority();
    void change_commentary();
    void add_subtask(Task* new_sub_task);
    void change_percent();
    void close_task();
    void activate_task();
    void print();
    void print_sub_task();//un peu différent de print, on ne fera qu'apparaitre les titres
    void print_title();




    
    

};

class Task_manager{
    protected:
    int nbr;
    std::vector<Task*> vect_ad_tache;
    public:
    Task_manager():nbr(0){};
    void read_save_file();
    void init();
    void print_task_list();
    void add_task();
    std::string ask_priority();
    std::string ask_status();
    void select_task(int n);
    void reinit_task_manager();
    void save_task();
    void modify_task(int n);
    void remove_task();


};

#endif//
