//
// Created by crazy_leaves on 16/5/9.
//

#include <iostream>
#include <string>
#include "sqlite3/sqlite3.h"

int callback(void *pv, int argc, char **argv, char **col_name){
    int i;
    std::cout << "2333" << std::endl;
    for(i = 0;i < argc;i++){
        std::cout << col_name[i] << " : " << argv[i] << std::endl;
    }
    return 0;
}

int main(void){
    std::cout << "open the db." << std::endl;
    sqlite3 *db_pointer;
    char *data = 0;
    char *error;
    int return_value;
    return_value = sqlite3_open("/Users/crazyLeaves/ClionProjects/C++/test.db", &db_pointer);
    if(!return_value){
        std::cout << "The db has opened." << std::endl;
    }
    int i;
    std::string insert("insert into account values(");
    std::string current;
    for(i = 0;i < 10;i++){
        current = insert;
        current += "100, ";
        current += "\'";
        current += ('a' + i);
        current += "\'";
        current += ", ";
        current += "2, ";
        current += "1";
        current += ('0' + i );
        current += ");";
        //std::cout << current << std::endl;

        //std::cout << sqlite3_exec(db_pointer, current.c_str(), NULL, NULL, &error);
    }
    std::string select("select * from account where rowid = 10");
    sqlite3_exec(db_pointer, select, callback, (void *)data, &error);
    std::cout << error;
    sqlite3_close(db_pointer);
    return 0;
}

