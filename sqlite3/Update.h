//
// Created by crazy_leaves on 16/5/17.
//
#include "sqlite3.h"
#include <string>
#include <iostream>


#ifndef C_UPDATE_H
#define C_UPDATE_H
class Update{
public:
    Update(sqlite3 *db);
    bool easy_update(std::string sql);
private:
    sqlite3* db_pointer;
    static int update_callback(void *pv, int argc, char **argv, char **col_name);
};
#endif //C_UPDATE_H
