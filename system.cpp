//
// Created by crazy_leaves on 16/5/8.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "system.h"



System::System(std::string file_path){
    this->db = new Database(file_path);
}


System::~System(){
    if(this->db != NULL){
        delete this->db;
    }

}










