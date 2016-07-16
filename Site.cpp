//
// Created by crazy_leaves on 16/6/12.
//

#include "Site.h"

Site::Site(int start, int end) {
    this->start = start;
    this->end = end;
    this->current = this->start;
}

int Site::get_start_site() {
    return this->start;
}

int Site::get_end_site() {
    return this->end;
}

int Site::get_current_site() {
    return this->current;
}

bool Site::set_current_site(int num) {
    this->current = num;
    return true;
}
