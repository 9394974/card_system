//
// Created by crazy_leaves on 16/5/8.
//

#include "Teacher.h"


Teacher::Teacher(int number, int money, std::string name, int times) : Person(number, money, name, times){
    this->kind = 0;
}

bool Teacher::decrease_money_once() {
    return false;
}

Teacher::~Teacher() {

}