//
// Created by crazy_leaves on 16/5/8.
//

#ifndef C_TEACHER_H
#define C_TEACHER_H


#include "../person.h"

class Teacher : public Person {
public:
    Teacher(int number, int money, std::string name, int times);
    bool decrease_money_once() override;
};

#endif //C_TEACHER_H
