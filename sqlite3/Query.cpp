//
// Created by crazy_leaves on 16/5/17.
//

#include "Query.h"

int Query::query_callback(void *pv, int argc, char **argv, char **col_name) {
    std::vector<std::map<std::string, std::string> > *container = static_cast<std::vector<std::map<std::string, std::string> > *>(pv);

    std::map<std::string, std::string> temp;
    int i;
    for(i = 0;i < argc;i++){
        temp.insert({col_name[i], argv[i]});
    }

    container->push_back(temp);

    return 0;
}

Query::Query(sqlite3 *db) {
    this->db_pointer = db;
}


bool Query::easy_query(std::string sql, std::vector<std::map<std::string, std::string> >& container) {
    char *error = 0;
    sqlite3_exec(this->db_pointer, sql.c_str(), query_callback, (void *)&container, &error);
    //std::cout << error 蜜汁bug
    return true;
}
