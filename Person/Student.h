//
// Created by crazy_leaves on 16/5/8.
//

#ifndef C_STUDENT_H
#define C_STUDENT_H



#include "../person.h"

class Student : public Person {
public:
    Student(int number, int money, std::string name, int times);
    bool decrease_money_once() override;
};

#endif //C_STUDENT_H