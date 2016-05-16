//
// Created by crazy_leaves on 16/5/8.
//

#include "Student.h"

Student::Student(int number, int money, std::string name, int times) : Person(number, money, name, times){
    this->kind = 1;
}


bool Student::decrease_money_once() {
    int temp;
    if(this->has_enough_money()){
        temp = this->get_left_money();
        if(temp > 2){
            temp -= 2;
            this->set_left_money(temp);
            return true;
        }
    }
    return false;
}