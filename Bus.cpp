//
// Created by crazy_leaves on 16/5/18.
//

#include "Bus.h"

Bus::Bus(Database* db_pointer, int no) {
    this->db = db_pointer;
    this->current = 0;

    std::string sql = "select * from bus_info where number = ";
    sql += std::to_string(no);
    if(!this->db->query_command(sql, this->info)){
        std::cerr << "The bus failed to init." << std::endl;
        exit(0);
    }
}

Bus::~Bus(){
    this->person_down();

    if(current != nullptr){
        delete current;
    }

    if(db){
        delete db;
    }
}

bool Bus::person_up(int people_no) {

    if(!this->number_check(people_no)){
        std::cerr << "Your number is invalid." << std::endl;
        return false;
    }


    std::string query_sql = "select rowid, * from account where rowid = ";
    query_sql += std::to_string(people_no);
    std::vector<std::map<std::string, std::string> > people_info;
    if(!this->db->query_command(query_sql, people_info)){
        return false;
    }

    int kind = this->d_string_to_int("kind", people_info);
    int money = this->d_string_to_int("money", people_info);
    int rowid = this->d_string_to_int("rowid", people_info);
    int times = this->d_string_to_int("times", people_info);
    std::string name = people_info[0].find("name")->second;

    this->person_initialize(rowid, money, name, times, kind);

    if(!this->handle_card()){
        return false;
    }

    this->display_information();

    return true;
}

bool Bus::person_down(int people_no) {
    if(!this->person_destruct(people_no)){
        return false;
    }
    return true;
}

bool Bus::person_down() {
    Person *down;
    this->current = nullptr;

    for(auto i = this->container.begin();i != this->container.end();i++){
        down = *i;
        if(down != nullptr){
            delete down;
            *i = nullptr;
        }
    }

    return true;
}



int Bus::d_string_to_int(std::string target, v_dict source) {
    return atoi((source[0].find(target)->second).c_str());
}

bool Bus::number_check(int number) {

    std::string sql = "select max(rowid) as max_rowid  from account;";

    v_dict max_rowid;

    if(!this->db->query_command(sql, max_rowid)){
        return false;
    }

    this->max_people_number = atoi((max_rowid[0].find("max_rowid")->second).c_str());

    if(number > this->max_people_number || number < 0){
        return false;
    }

    return true;
}

bool Bus::person_initialize(int card_number, int left_money, std::string name, int times, int kind) {
    Person *current;

    if(kind == 0){
        current = new Teacher(card_number, left_money, name, times);
    }
    else if(kind == 1){
        current = new Student(card_number, left_money, name, times);
    }
    else if(kind == 2){
        current = new Restrict(card_number, left_money, name, times);
    }
    else{
        std::cerr << "no this kinds" << std::endl;
        return false;
    }

    this->container.push_back(current);
    this->current = current;

    return true;
}

bool Bus::handle_card(){

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

bool Bus::person_destruct(int people_no) {

    this->current = nullptr;
    Person* down = nullptr;
    for(auto begin = this->container.begin();begin != this->container.end();begin++){
        if((*begin)->get_card_number() == people_no){
            down = *begin;
            delete down;
            *begin = nullptr;
            return true;
        }
    }

    std::cerr << "The person is not in the bus." << std::endl;

    return false;
}

void Bus::display_information() {
    std::cout << "Welcome to bus " + this->info[0].find("number")->second << std::endl;
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