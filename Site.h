//
// Created by crazy_leaves on 16/6/12.
//

#ifndef C_SITE_H
#define C_SITE_H

class Site{
public:
    Site(int start, int end);
    int get_start_site();
    int get_end_site();
    int get_current_site();
    bool set_current_site(int num);

private:
    int start;
    int end;
    int current;
};

#endif //C_SITE_H
