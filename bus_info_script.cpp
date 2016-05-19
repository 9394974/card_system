//
// Created by crazy_leaves on 16/5/19.
//

#include <iostream>
#include <string>
#include "Database.h"

int main(void){
    Database db("/Users/crazyLeaves/ClionProjects/C++/test.db");
    std::string sql("insert into bus_info values(\'");
    std::string origin = sql;
    int i;

    for(i = 20;i < 30;i++){
        sql = origin;
        sql += std::to_string(i);
        sql +=  "\', ";
        sql += "2, \'";
        sql += ('a' + i - 20);
        sql += "\', ";
        sql += "30, ";
        sql += "time(\'07:30:00\'), time(\'19:00:00\'), ";
        sql += std::to_string(i);
        sql += ")";
        std::cout << sql << std::endl;
        db.insert_command(sql);
    }

    return 0;
}