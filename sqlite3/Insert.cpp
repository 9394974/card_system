//
// Created by crazy_leaves on 16/5/17.
//

#include "Insert.h"

Insert::Insert(sqlite3* db){
    this->db_pointer = db;
}

bool Insert::easy_insert(std::string sql) {
    int rc;
    char *error = 0;

    rc = sqlite3_exec(this->db_pointer, sql.c_str(), NULL, NULL, &error);

    if(rc != SQLITE_OK){
        std::cerr << "The insertion has failed because of " << error << std::endl;
        return false;
    }

    return true;
}