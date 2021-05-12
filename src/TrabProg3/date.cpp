#include <iostream>
#include <string>
#include "Date.hpp"

using namespace std;

Date::Date(){
}

Date::~Date(){
	// TODO Auto-generated destructor stub
}

void Date::enterDate(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

void Date::printDate(){
    cout<<this->day<<"/"<<this->month<<"/"<<year;
}

int Date::bi(int year){
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}   

int Date::returnDay(){
    return this->day;
}

int Date::returnMonth(){
    return this->month;
}

int Date::returnYear(){
    return this->year;
}

unsigned int Date::distanceYears(Date &end){
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

    fdays = end.returnDay();
    dbi = bi(end.returnYear());
    for(int i = end.returnMonth() - 1; i > 0; --i)
        fdays += days_month[dbi][i];

    while (this->year < end.returnYear()){
        def_years += 365 + bi(this->year++);
    }

    return def_years - idays + fdays;
}

void Date::turnInto(Date &new_date){
    this->day = new_date.returnDay();
    this->month = new_date.returnMonth();
    this->year = new_date.returnYear();
}

int Date::compareDate(Date other, Date another){
    if(other.returnYear() == another.returnYear()){
        if(other.returnMonth() == another.returnMonth()){
            if(other.returnDay() == another.returnDay()){
                return 0;
            }
        }
    }

    return 1;
}

int Date::idade(Date &other){
    int idade = other.returnYear() - this->year;

    if(other.returnMonth() > this->month){
        idade--;
    } else if((other.returnMonth() == this->month) && (other.returnDay() > this->day)){
        idade--;
    }

    return idade;
}

bool Date::compareTo(Date other){
    if(this->returnYear() > other.returnYear()){
        return true;
    } else if((this->returnYear() == other.returnYear()) && (this->returnMonth() > other.returnMonth())){
        return true;
    } else if((this->returnYear() == other.returnYear()) && (this->returnMonth() == other.returnMonth()) && (this->returnDay() > other.returnDay())){
        return true;
    }

    return false;
}
