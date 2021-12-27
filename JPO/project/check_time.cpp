#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "check_time.h"

using namespace std;

int check_date(string date_start, string date_end){

    int buffor = stoi(date_start.substr(6,4));
    int buffor_stop = stoi(date_end.substr(6,4));
    if( buffor == buffor_stop){
        int buffor = stoi(date_start.substr(3,2));
        int buffor_stop = stoi(date_end.substr(3,2)); 

        if( buffor == buffor_stop){
            int buffor = stoi(date_start.substr(0,2));
            int buffor_stop = stoi(date_end.substr(0,2)); 
            if( buffor > buffor_stop ){
                cout << "zla data\n";
                return 1;
            }
            else
                return 0;
            
        }
        else if( buffor > buffor_stop ){
            cout << "zla data\n";
            return 1;
        }
        else    
            return 0;   
        }
    else if( buffor > buffor_stop ){
        cout << "zla data\n";
        return 1;
    }
    else    
        return 0;

}


int check_calendary(string date){
    int buffor_month = stoi(date.substr(3,2));
    int buffor_day = stoi(date.substr(0,2));

    if(number_of_days[buffor_month-1] >= buffor_day){
        //day's are "ok"
        if(buffor_month <= 12){
            //month's are "ok"
            return 0;
        }
    }
    cout << "podano nieprawidlowa dat\n";
    return 1;
}


int number_of_days_in_between(string date_start, string date_end){
    int buffor_month_start = stoi(date_start.substr(3,2));
    int buffor_day_start = stoi(date_start.substr(0,2));
    int buffor_year_start = stoi(date_start.substr(6,4));

    int buffor_month_end = stoi(date_end.substr(3,2));
    int buffor_day_end = stoi(date_end.substr(0,2));
    int buffor_year_end = stoi(date_end.substr(6,4));


    int days=0;
    days = (buffor_year_end - buffor_year_start )*365;
    days += (counting_of_days[buffor_month_end-1]+buffor_day_end) - (counting_of_days[buffor_month_start-1]+ buffor_day_start);
    
    return days;
}