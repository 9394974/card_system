//
// Created by crazy_leaves on 16/5/17.
//

#include "Update.h"

Update::Update(sqlite3* db) {
    this->db_pointer = db;
}

bool Update::easy_update(std::string sql) {
    int rc;
    char *error = 0;

    rc = sqlite3_exec(this->db_pointer, sql.c_str(), update_callback, NULL, &error);

    if(rc != SQLITE_OK){
        std::cerr << "The update has failed because of " << error << std::endl;
        return false;
    }

    sqlite3_free(error);

    return true;
}

int Update::update_callback(void *pv, int argc, char **argv, char **col_name) {

    return 1;
}