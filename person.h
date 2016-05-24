//
// Created by crazy_leaves on 16/5/8.
//

#ifndef C_PERSON_H
#define C_PERSON_H

#include <string>

class Person {
public:
    Person() = default;
    Person(int number, int money, std::string name, int times);

    int get_card_number();
    int get_left_money();
    std::string get_possessor_name();
    int get_times();
    bool set_sum_times(int times);
    int get_sum_times();

    void set_possessor_name(std::string name);
    virtual int get_kinds();
    bool increase_times();
    virtual bool decrease_money_once() = 0;
    virtual ~Person();


private:
    int card_number;
    int left_money;
    std::string possessor_name;
    int times;
    int sum_times;

protected:
    //teacher card is 0.
    //student card is 1.
    //restrict card is 2.
    int kind = -1;
    void set_left_money(int money);
    void set_times(int times);
    bool has_enough_money();

};


#endif //C_PERSON_H

