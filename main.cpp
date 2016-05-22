#include <iostream>
#include "system.h"

int main() {
    System main_system("/Users/crazyLeaves/ClionProjects/C++/test.db");
    main_system.query_bus(4);
    main_system.init_bus(4, "06:00:00");
    Bus* test = main_system.get_current_bus();
    test->person_up(10);
    test->person_up(20);
    test->person_down();
    main_system.end_bus(4, "18:30:00");
    return 0;
}