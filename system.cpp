//
// Created by crazy_leaves on 16/5/8.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "system.h"



System::System(std::string file_path){
    this->db = new Database(file_path);
    this->current = NULL;
    this->max_number = 0;
}


System::~System(){
    if(this->db != NULL){
        delete this->db;
    }

    if(this->current != NULL){
        delete this->current;
    }

}


bool System::query_number_and_handle(int number) {

    if(!this->number_check(number)){
        std::cerr << "Your number is invalid." << std::endl;
        return false;
    }


    std::string query_sql = "select rowid, * from account where rowid = ";
    query_sql += std::to_string(number);
    std::vector<std::map<std::string, std::string> >info;
    if(!this->db->query_command(query_sql, info)){
        return false;
    }

    int kind = this->d_string_to_int("kind", info);
    int money = this->d_string_to_int("money", info);
    int rowid = this->d_string_to_int("rowid", info);
    int times = this->d_string_to_int("times", info);
    std::string name = info[0].find("name")->second;

    if(!this->person_initalize(rowid, money, name, times, kind)){
        return false;
    }


    if(!this->handle()){
        return false;
    }

    this->display_information();


    if(!person_destruct()){
        return false;
    }


    return true;
}

bool System::handle(){

    this->current->decrease_money_once();
    this->current->increase_times();
    int card_number = this->current->get_card_number();
    int left_money = this->current->get_left_money();
    int times = this->current->get_times();


    std::string sql = "update account set money = " + std::to_string(left_money) +
                      ", times = " + std::to_string(times) +
                      " where rowid = " + std::to_string(card_number);

    if(!(this->db->update_command(sql))){
        return false;
    }

    return true;
}

void System::display_information() {
    std::string name[3] = {"Teacher", "Student", "Restrict"};
    time_t t = time(0);
    struct tm * now = localtime(&t);
    std::cout << "Today is " << (now->tm_year + 1900) << '-'
                             << (now->tm_mon + 1) << '-'
                             << now->tm_mday
                             << std::endl;
    std::cout << "The kind of your card is: " << name[this->current->get_kinds()] << std::endl;
    std::cout << "Your card number is: " << this->current->get_card_number() << std::endl;
    std::cout << "Your name is: " << this->current->get_possessor_name()<< std::endl;
    std::cout << "The money you left is: " << this->current->get_left_money() << std::endl;
    std::cout << "You have taken bus for " << this->current->get_times() << " times this month." << std::endl;
}


bool System::person_initalize(int card_number, int left_money, std::string name, int times, int kind) {
    if(this->current != NULL){
        std::cerr << "The person has not been destructed." << std::endl;
        return false;
    }

    if(kind == 0){
        this->current = new Teacher(card_number, left_money, name, times);
    }
    else if(kind == 1){
        this->current = new Student(card_number, left_money, name, times);
    }
    else if(kind == 2){
        this->current = new Restrict(card_number, left_money, name, times);
    }
    else{
        std::cerr << "no this kinds" << std::endl;
        return false;
    }

    return true;
}

bool System::person_destruct() {
    if(this->current == NULL){
        std::cerr << "The person has been destructed already.You can't use this function to a null pointer." << std::endl;
        return false;
    }

    delete this->current;
    return true;
}

bool System::number_check(int number) {

    std::string sql = "select max(rowid) as max_rowid  from account;";

    v_dict max_rowid;

    if(!this->db->query_command(sql, max_rowid)){
        return false;
    }

    this->max_number = atoi((max_rowid[0].find("max_rowid")->second).c_str());

    if(number > this->max_number || number < 0){
        return false;
    }

    return true;
}

int System::d_string_to_int(std::string target, v_dict source) {
    return atoi((source[0].find(target)->second).c_str());
}
