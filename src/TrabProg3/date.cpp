#include <iostream>
#include <string>
#include "date.hpp"

using namespace std;

date::date(){
}

void date::enter_date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

void date::print_date(){
    cout<<this->day<<"/"<<this->month<<"/"<<year<<endl;
}

int date::bi(int year){
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}   

int date::return_day(){
    return this->day;
}

int date::return_month(){
    return this->month;
}

int date::return_year(){
    return this->year;
}

unsigned int date::distance_years(date end){
    int days_month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    unsigned int idays;
    unsigned int fdays;	
    unsigned int def_years = 0;

    int dbi;

    idays = this->day;
    dbi = bi(this->year);
    for (int i = this->month - 1; i > 0; --i){
        idays += days_month[dbi][i];
    }

    fdays = end.return_day();
    dbi = bi(end.return_year());
    for(int i = end.return_month() - 1; i > 0; --i)
        fdays += days_month[dbi][i];

    while (this->year < end.return_year()){
        def_years += 365 + bi(this->year++);
    }

    return def_years - idays + fdays;
}

void date::turn_into(date new_date){
    this->day = new_date.return_day();
    this->month = new_date.return_month();
    this->year = new_date.return_year();
}

int date::compare_date(date other, date another){
    if(other.return_year() == another.return_year()){
        if(other.return_month() == another.return_month()){
            if(other.return_day() == another.return_day()){
                return 0;
            }
        }
    }

    return 1;
}

int date::idade(date other){
    int idade = other.return_year() - this->year;

    if(other.return_month() > this->month){
        idade--;
    } else if(other.return_day() > this->day){
        idade--;
    }

    return idade;
}