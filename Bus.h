//
// Created by crazy_leaves on 16/5/18.
//
#include <string>
#include <vector>
#include "Database.h"

#ifndef C_BUS_H
#define C_BUS_H

class Bus{
public:
    Bus(Database* db_pointer, int no);//几号车,剩余数据从数据库读
    ~Bus();
private:
    Database* db;
    std::string number;
    std::string driver_name;
    std::string license;
    int type;
    int max_people;
    std::vector<std::string, std::string> standard_time;
};

#endif //C_BUS_H
