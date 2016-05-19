//
// Created by crazy_leaves on 16/5/18.
//

#include "person.h"
#include "sqlite3/Database.h"
#include "Person/Teacher.h"
#include "Person/Student.h"
#include "Person/Restrict.h"
#include <string>
#include <vector>

#ifndef C_BUS_H
#define C_BUS_H

class Bus{
public:
    Bus(Database* db_pointer, int no);
    bool person_up(int people_no);
    bool person_down(int people_no);
    bool person_down();
    void display_information();
    ~Bus();

private:
    Database* db;
    v_dict info;
    std::vector<Person *> container;
    Person *current;
    int max_people_number;

    int d_string_to_int(std::string target, v_dict source);
    bool number_check(int number);
    bool person_initialize(int card_number, int left_money, std::string name, int times, int kind);
    bool handle_card();
    bool person_destruct(int people_no);
};

#endif //C_BUS_H
