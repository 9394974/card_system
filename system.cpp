//
// Created by crazy_leaves on 16/5/8.
//
#include <iostream>
#include "system.h"

System::System(std::string file_path){
    this->db = new Database(file_path);
    this->current = nullptr;
}

bool System::init_bus(int no, std::string start_time) {
    Bus *new_bus = new Bus(this->db, no, start_time);
    this->container.push_back(new_bus);
    this->current = new_bus;
    return true;
}

bool System::end_bus(int no, std::string end_time) {
    std::cout << std::string("The bus ") + std::to_string(this->current->get_bus_number()) + " start at " + this->current->real_start_time + " and end at " + this->current->real_end_time << std::endl;
    std::cout << std::string("Today it has loaded ") + std::to_string(this->current->get_people_times()) + " people" << std::endl;

    for(auto i = this->container.begin();i != container.end();i++){
        if((*i)->get_bus_number() == no){
            (*i)->set_end_time(end_time);
            delete *i;
            *i = nullptr;
            return true;
        }
    }

    this->current = nullptr;
    return false;
}

bool System::end_bus(std::string end_time){


    for(auto i = this->container.begin();i != container.end();i++){
        if(*i != nullptr){
            (*i)->set_end_time(end_time);
            delete *i;
            *i = nullptr;
        }
    }
    return true;
}

Bus* System::get_current_bus() {
    return this->current;
}

void System::query_bus(int no){
    v_dict bus_info;

    std::string sql = "select * from bus_info where number = " + std::to_string(no);

    this->db->query_command(sql, bus_info);

    std::string start = bus_info[0].find("time_start")->second;

    std::string end = bus_info[0].find("time_end")->second;

    std::cout << ("Bus " + std::to_string(no) + " is supposed to start at " + start + " and end at " + end) << std::endl;

}


System::~System(){
    if(this->db != nullptr){
        delete this->db;
    }
}










