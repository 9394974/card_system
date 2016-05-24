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
    Bus(Database* db_pointer, int no, std::string start_time);
    bool person_up(int people_no);
    bool person_down(int people_no);
    bool person_down();
    void bus_information();
    void people_information();
    int get_bus_number();
    bool set_end_time(std::string end_time);
    std::string real_start_time;
    std::string real_end_time;
    int get_people_times();
    ~Bus();

private:
    Database* db;
    v_dict info;
    std::vector<Person *> container;
    Person *current;
    int valid_people_number;
    int current_load;
    int people_times;


    int d_string_to_int(std::string target, v_dict source);
    std::string d_string(std::string target, v_dict source);
    bool number_check(int number);
    bool load_check();
    bool person_initialize(int card_number, int left_money, std::string name, int times, int kind);
    bool handle_card();
    bool person_destruct(int people_no);
    bool increase_people(int identity);
};

#endif //C_BUS_H
