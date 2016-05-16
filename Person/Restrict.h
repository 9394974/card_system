//
// Created by crazy_leaves on 16/5/8.
//

#ifndef C_RESTRICT_H
#define C_RESTRICT_H



#include "../person.h"


class Restrict : public Person {
public:
    Restrict(int number, int money, std::string name, int times);
    bool has_enough_times();
    bool decrease_money_once() override;
};

#endif //C_RESTRICT_H
