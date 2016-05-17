//
// Created by crazy_leaves on 16/5/16.
//

#include "DataBase.h"

Database::Database(std::string file_path) {
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
            std::cerr << "The program is exiting and you should create your db file maually." << std::endl;
            exit(0);
        }
    }

    sqlite3_open(file_path.c_str(), &this->db);
}

bool Database::exec_command(std::string sql) {

}

bool Database::query_command(std::string sql, std::map& container) {
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

}