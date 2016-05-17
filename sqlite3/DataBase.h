//
// Created by crazy_leaves on 16/5/16.
//
#include "sqlite3.h"
#include "Query.h"
#include "Update.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>

#ifndef C_DATABASE_H
#define C_DATABASE_H

class Database{
public:
    Database(std::string file_path);
    bool exec_command(std::string sql);
    bool query_command(std::string sql, std::vector<std::map<std::string, std::string> >& container);
    bool update_command(std::string sql);
    void test_display(std::vector<std::map<std::string, std::string> >& temp);

private:
    Query* query;
    Update* update;
    sqlite3* db;
    bool check_rc(int rc);
};

#endif //C_DATABASE_H
