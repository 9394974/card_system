//
// Created by crazy_leaves on 16/5/18.
//

#include "Bus.h"

Bus::Bus(Database* db_pointer, int no) {
    this->number = no;
    this->db = db_pointer;

    std::string sql = "select * from bus_info where number = ";
    sql += std::to_string(no);
    v_dict info;
    this->db->query_command(sql, info);



}