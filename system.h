//
// Created by crazy_leaves on 16/5/8.
//

#ifndef C_SYSTEM_H
#define C_SYSTEM_H

#include "person.h"
#include "sqlite3.h"
#include "Teacher.h"
#include "Student.h"
#include "Restrict.h"
#include "Database.h"

typedef std::vector<std::map<std::string, std::string>> v_dict;

class System {
public:
    System(std::string file_path);
    bool query_number_and_handle(int number);
    ~System();

private:
    Database* db;
    Person *current;
    int max_number;

    bool handle();
    bool person_initalize(int card_number, int left_money, std::string name, int times, int kind);
    bool person_destruct();
    void display_information();
    int d_string_to_int(std::string target, v_dict source);
    bool number_check(int number);
};

#endif //C_SYSTEM_H