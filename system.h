//
// Created by crazy_leaves on 16/5/8.
//

#ifndef C_SYSTEM_H
#define C_SYSTEM_H

#include "person.h"
#include "Teacher.h"
#include "Student.h"
#include "Restrict.h"
#include "Database.h"



class System {
public:
    System(std::string file_path);
    ~System();

private:
    Database* db;



};

#endif //C_SYSTEM_H