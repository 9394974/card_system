#include <iostream>
#include "Bus.h"

int main() {
    Bus test(new Database("/Users/crazyLeaves/ClionProjects/C++/test.db"), 4);
    test.person_up(10);
    test.person_down(10);
    return 0;
}