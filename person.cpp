//
// Created by crazy_leaves on 16/5/8.
//
#include <iostream>
#include "person.h"


Person::Person(int number, int money, std::string name, int times) {
    this->card_number =  number;
    this->left_money = money;
    this->possessor_name = name;
    this->times = times;
}

Person::~Person() {

}


int Person::get_card_number() {
    return card_number;
}

int Person::get_left_money() {
    return left_money;
}

std::string Person::get_possessor_name() {
    return possessor_name;
}

int Person::get_times() {
    return times;
}



void Person::set_left_money(int money) {
    this->left_money = money;
}

void Person::set_possessor_name(std::string name) {
    this->possessor_name = name;
}


void Person::set_times(int times) {
    this->times = times;
}



bool Person::has_enough_money() {
    int money = this->get_left_money();
    if(money < 2){
        std::cout << "You have insufficient credits which is lower than 2.Please recharge your card right row.";
        return false;
    }
    else{
        if(money >2 && money <= 5){
            std::cout << "You have insufficient credits which is lower than 5.Please recharge your card soon.";
        }
        return true;
    }
}

bool Person::increase_times() {
    int temp = this->get_times();
    if(temp >= 0){
        temp++;
        this->set_times(temp);
        return true;
    }
    std::cout << "System error.";
    return false;
}



int Person::get_kinds(){
    return kind;
}





