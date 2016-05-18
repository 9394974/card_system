//
// Created by crazy_leaves on 16/5/16.
//

#include <iostream>
#include <vector>
#include <map>
#include "DataBase.h"

int main(void){
    Database db("/Users/crazyLeaves/ClionProjects/C++/test.db");

    std::vector<std::map<std::string, std::string> > temp;
    db.query_command("select rowid, * from account", temp);

    db.test_display(temp);
    return 0;
}