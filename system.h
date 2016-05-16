//
// Created by crazy_leaves on 16/5/8.
//

#ifndef C_SYSTEM_H
#define C_SYSTEM_H

#include "sqlite3/sqlite3.h"
#include "person.h"



class System {
public:
    System();
    bool init();
    bool query_number_and_handle(int number);

    bool close();

private:
    sqlite3 *database;
    Person *current;
    int max_number;

    bool handle();
    bool check_rc(int rc);
    bool person_initalize(int card_number, int left_money, std::string name, int times, int kind);
    bool person_destruct();
    void display_information();
    bool number_check(int number);
    static int query_callback(void* pv, int argc, char **argv, char **col_name);
    static int number_callback(void* pv, int argc, char **argv, char **col_name);
};

#endif //C_SYSTEM_H