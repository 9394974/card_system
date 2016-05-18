//
// Created by crazy_leaves on 16/5/18.
//

#include "../Bus.h"
#include <string>
#include <vector>

#ifndef C_COMMONBUS_H
#define C_COMMONBUS_H

class CommonBus : public Bus {
public:
    CommonBus();
    bool init(std::string start_time);
    bool end(std::string end_time);
private:
    std::vector<std::string, std::string> real_time;
};

#endif //C_COMMONBUS_H
