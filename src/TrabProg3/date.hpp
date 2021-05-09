#ifndef date_h_
#define date_h_

#include <iostream>
#include <string>

using namespace std;

class date{
    private:
    int day;
    int month;
    int year;
    
    public:
    // date(int &d, int &m, int &y);
    date();
    
    void enter_date(int d, int m, int y);

    void print_date();

    int bi(int year);

    int return_day();

    int return_month();

    int return_year();

    unsigned int distance_years(date end);

    void turn_into(date new_date);

    int compare_date(date other, date another);

    int idade(date other);
};

#endif /* date_h_ */