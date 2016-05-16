//
// Created by crazy_leaves on 16/5/8.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "system.h"
#include "sqlite3.h"
#include "Teacher.h"
#include "Student.h"
#include "Restrict.h"


System::System(){
    this->database = 0;
    this->current = NULL;
    this->max_number = 0;
}

bool System::init(){
    int rc = sqlite3_open("/Users/crazyLeaves/ClionProjects/C++/test.db", &this->database);

    if(rc != SQLITE_OK){
        std::cerr << "The database failed to open." << std::endl;
        return false;
    }

    return true;
}

bool System::query_number_and_handle(int number) {

    int rc;
    char *error = 0;

    if(!this->number_check(number)){
        std::cerr << "Your number is invalid." << std::endl;
        return false;
    }



    std::string query_sql = "select rowid, * from account where rowid = ";
    query_sql += std::to_string(number);
    rc = sqlite3_exec(this->database, query_sql.c_str(), System::query_callback, (void *)this, &error);
    sqlite3_free(error);

    if(!check_rc(rc)){
        std::cerr << "Query has failed because of " << error <<std::endl;
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


    int rc;
    std::string sql = "update account set money = " + std::to_string(left_money) +
                      ", times = " + std::to_string(times) +
                      " where rowid = " + std::to_string(card_number);
    char *error = 0;

    rc = sqlite3_exec(this->database, sql.c_str(), NULL, NULL, &error);
    sqlite3_free(error);

    if(!check_rc(rc)){
        std::cerr << "Handle has failed because of " << error <<std::endl;
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

bool System::close() {
    int rc = sqlite3_close(this->database);

    if(!check_rc(rc)){
        std::cerr << "The database failed to close." << std::endl;
        return true;
    }

    return false;
}

bool System::check_rc(int rc) {
    if(rc != SQLITE_OK){
        return false;
    }
    return true;
}

int System::query_callback(void *pv, int argc, char **argv, char **col_name) {
    int i;
    int number, money, kind, times;
    std::string name;
    System *temp = static_cast<System *>(pv);
    number = atoi(argv[0]);
    money = atoi(argv[1]);
    name = std::string(argv[2]);
    kind = atoi(argv[3]);
    times = atoi(argv[4]);

    if(!temp->person_initalize(number, money, name, times, kind)){
        //non-zero means false;
        return 1;
    }

    return 0;
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

    int rc;
    char *error = 0;
    std::string sql = "select max(rowid) from account;";

    rc = sqlite3_exec(this->database, sql.c_str(), System::number_callback, (void *)this, &error);

    if(!check_rc(rc)){
        std::cerr << "Query has failed because of " << error <<std::endl;
        return false;
    }

    if(number > this->max_number || number < 0){
        return false;
    }

    return true;
}

int System::number_callback(void *pv, int argc, char **argv, char **col_name) {
    System *current = static_cast<System *>(pv);
    current-> max_number = atoi(argv[0]);
    return 0;
}

