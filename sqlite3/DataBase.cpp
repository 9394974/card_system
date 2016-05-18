//
// Created by crazy_leaves on 16/5/16.
//

#include "Database.h"

Database::Database(std::string file_path) {
    this->query = NULL;
    this->insert = NULL;
    this->update = NULL;


    std::fstream file;

    file.open(file_path, std::ios::in);

    if(!file){
        file.close();
        std::string input;

        std::cout << "The db file not exists.If you want to create a db file,enter Y or N :";

        std::cin >> input;
        while(input != "Y" || input != "N"){
            std::cerr << "You have enter the wrong word.Please enter again." << std::endl;
            std::cin >> input;
        }

        if(input == "Y"){
            file.open(file_path, std::ios::out);
        }
        else{
            std::cerr << "The program is exiting and you should create your db file manually." << std::endl;
            exit(0);
        }
    }

    int rc = sqlite3_open(file_path.c_str(), &this->db);

    if(rc != SQLITE_OK){
        std::cerr << "The database failed to open.Program is exiting." << std::endl;
        exit(0);
    }

}

bool Database::exec_command(std::string sql) {
    char *error = 0;
    int rc = sqlite3_exec(this->db, sql.c_str(), NULL, NULL, &error);

    if(!check_rc(rc)){
        std::cerr << "The command has failed because of " << error << std::endl;
        return false;
    }

    return true;
}

bool Database::query_command(std::string sql, std::vector<std::map<std::string, std::string> >& container) {
    if(this->query != NULL){
        delete this->query;
    }

    this->query = new Query(this->db);

    if(!this->query->easy_query(sql, container)){
        return false;
    }

    return true;
}

bool Database::update_command(std::string sql) {
    if(this->update != NULL){
        delete this->update;
    }

    this->update = new Update(this->db);

    if(!this->update->easy_update(sql)){
        return false;
    }

    return true;
}

void Database::test_display(std::vector<std::map<std::string, std::string> > &temp) {
    auto v_begin = temp.cbegin();

    while(v_begin != temp.cend()){
        auto d_begin = (*v_begin).cbegin();
        while(d_begin != (*v_begin).cend()){
            std::cout << d_begin->first << " : " << d_begin->second << std::endl;
            d_begin++;
        }
        v_begin++;
        std::cout << std::endl;
    }
}

bool Database::check_rc(int rc) {
    if(rc != SQLITE_OK){
        return false;
    }
    return true;
}