//
// Created by crazy_leaves on 16/5/8.
//

#ifndef C_SYSTEM_H
#define C_SYSTEM_H

#include <string>

#include "person.h"
#include "Teacher.h"
#include "Student.h"
#include "Restrict.h"
#include "Database.h"
#include "Bus.h"



class System {
public:
    System(std::string file_path);
    //bool bus_transaction(int number, std::string start_time, std::string end_time);
    bool init_bus(int no, std::string start_time);
    bool end_bus(std::string end_time);
    bool end_bus(int no, std::string end_time);
    Bus* get_current_bus();
    void query_bus(int no);
    int increase_card(int money, std::string name, int kind);
    bool delete_card(int no);
    ~System();

private:
    Database* db;
    std::vector<Bus *> container;
    Bus* current;
};

#endif //C_SYSTEM_H