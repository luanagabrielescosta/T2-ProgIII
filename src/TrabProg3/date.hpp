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
};

// int main(){
//     string date1, date2;

//     cin >> date1;
//     cin >> date2;

//     int day1 = 0, day2 = 0, month1 = 0, month2 = 0, year1 = 0, year2 = 0;

//     day1 = (date1[0] - 48)*10 + date1[1] - 48;
//     day2 = (date2[0] - 48)*10 + date2[1] - 48;
//     month1 = (date1[3] - 48)*10 + date1[4] - 48;
//     month2 = (date2[3] - 48)*10 + date2[4] - 48;
//     year1 = (date1[6] - 48)*1000 + (date1[7] - 48)*100 + (date1[8] - 48)*10 + date1[9] - 48;
//     year2 = (date2[6] - 48)*1000 + (date2[7] - 48)*100 + (date2[8] - 48)*10 + date2[9] - 48;
    
//     date luaninha = date(day1,month1,year1);
//     luaninha.print_date();

//     date luana = date(day2,month2,year2);
//     luana.print_date();

//     // cout << luana.return_year();
//     cout << luaninha.distance_years(luana) << endl;
// };

#endif /* date_h_ */