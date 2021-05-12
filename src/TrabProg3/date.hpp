#ifndef date_h_
#define date_h_

#include <iostream>
#include <string>

using namespace std;

class Date{
	// Atributos
    int day;
    int month;
    int year;
    
    public:
	// Constructor
    Date();
	// Destructor
    ~Date();

	// Métodos
    void enterDate(int d, int m, int y);

    void printDate();

    int bi(int year);

    int returnDay();

    int returnMonth();

    int returnYear();

    unsigned int distanceYears(Date &end);

    void turnInto(Date &new_date);

    int compareDate(Date other, Date another);

    int idade(Date &other);

    bool compareTo(Date other);
};

#endif /* date_h_ */