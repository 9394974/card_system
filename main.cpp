#include <iostream>
#include "system.h"

int main() {
    System main_system("/Users/crazyLeaves/ClionProjects/C++/test.db");
    main_system.query_number_and_handle(20);

    return 0;
}