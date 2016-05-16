#include <iostream>
#include "system.h"

int main() {
    System main_system;
    main_system.init();
    main_system.query_number_and_handle(15);
    main_system.close();
    return 0;
}