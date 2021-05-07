#include <iostream>
#include <string>

using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;
    
    public:
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    
    void print_date(){
        cout<<this->day<<"/"<<this->month<<"/"<<year<<endl;
    }

    int bi(int year){
        return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
    }   

    int return_day(){
        return this->day;
    }

    int return_month(){
        return this->month;
    }

    int return_year(){
        return this->year;
    }


    unsigned int distance_years(Date end){
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
};

int main(){
    string date1, date2;

    cin >> date1;
    cin >> date2;

    int day1 = 0, day2 = 0, month1 = 0, month2 = 0, year1 = 0, year2 = 0;

    day1 = (date1[0] - 48)*10 + date1[1] - 48;
    day2 = (date2[0] - 48)*10 + date2[1] - 48;
    month1 = (date1[3] - 48)*10 + date1[4] - 48;
    month2 = (date2[3] - 48)*10 + date2[4] - 48;
    year1 = (date1[6] - 48)*1000 + (date1[7] - 48)*100 + (date1[8] - 48)*10 + date1[9] - 48;
    year2 = (date2[6] - 48)*1000 + (date2[7] - 48)*100 + (date2[8] - 48)*10 + date2[9] - 48;
    // cout << day1 << endl;
    // cout << date1[0];

    // cout << day1 << ":" << month1 << ":" << year1 << endl;
    // cout << day2 << ":" << month2 << ":" << year2 << endl;
    // cout << date1 << endl;
    // cout << date2 << endl;

    
    Date luaninha = Date(day1,month1,year1);
    luaninha.print_date();

    Date luana = Date(day2,month2,year2);
    luana.print_date();

    // cout << luana.return_year();
    cout << luaninha.distance_years(luana) << endl;
};