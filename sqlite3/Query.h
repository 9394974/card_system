//
// Created by crazy_leaves on 16/5/17.
//
#include "sqlite3.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>

#ifndef C_QUERY_H
#define C_QUERY_H

class Query{
public:
    Query(sqlite3* db);
    bool easy_query(std::string sql, std::vector<std::map<std::string, std::string> >& container);
private:
    sqlite3* db_pointer;
    static int query_callback(void *pv, int argc, char **argv, char **col_nam);
};

#endif //C_QUERY_H
