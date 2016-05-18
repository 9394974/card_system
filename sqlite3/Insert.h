//
// Created by crazy_leaves on 16/5/17.
//

#include <string>

#ifndef C_INSERT_H
#define C_INSERT_H

class Insert{
public:
    Insert(sqlite3* db);
    bool easy_insert(std::string sql);
private:
    sqlite3* db_pointer;
};

#endif //C_INSERT_H
