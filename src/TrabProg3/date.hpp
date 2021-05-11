#ifndef date_h_
#define date_h_

#include <iostream>
#include <string>

using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;
    
    public:
    Date();
    
    void enter_date(int d, int m, int y);

    void print_date();

    int bi(int year);

    int return_day();

    int return_month();

    int return_year();

    unsigned int distance_years(Date &end);

    void turn_into(Date &new_date);

    int compare_date(Date other, Date another);

    int idade(Date &other);

    bool compareTo(Date other);
};

#endif /* date_h_ */