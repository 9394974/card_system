//
// Created by crazy_leaves on 16/5/8.
//

#include "Restrict.h"
#include <iostream>

Restrict::Restrict(int number, int money, std::string name, int times) : Person(number, money, name, times){
    this->kind = 2;
}

bool Restrict::has_enough_times() {
    int times = this->get_times();
    if(times <= 20){
        if(times == 20){
            std::cout << "This is the last time for free.";
        }
        return true;
    }
    return false;
}

bool Restrict::decrease_money_once() {
    int temp;
    bool status = this->has_enough_times();
    if(status){
        return true;
    }
    else{
        if(this->get_times() == 21){
            std::cout << "You have run out of your times.It is time to take some money.";
        }
        if(this->has_enough_money()){
            temp = this->get_left_money();
            if(temp > 2){
                temp -= 2;
                this->set_left_money(temp);
                return true;
            }
        }
    }
    return false;
}

