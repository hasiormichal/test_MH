#include <string>
#include <iostream>
#include "check_functions.h"
#include "global.h"
//#include "class_car.cpp"


using namespace  std;

int check_ID(string liczba){
// ID must have 4 characters !! ---------------------------------
    if(liczba.length() != 4){
        cout << "Bad ID format, use XXXX\n";
        return 1;
    }
// ID should have only numbers ----------------------    
    if(check_string_number(liczba))
        return 1;

//check ID if it is used ----------------------------
    for(auto check_id: all_id){
        if(check_id == liczba){
            cout << "This ID is already used\n";
            return 1;
        }
    }
    return 0; 
}


int check_year (string year){
    if(check_string_number(year))
        return 1;
   
    if(stoi(year) <= 1900 || stoi(year) >= 2050){
        cout << "incorect date\n";
        return 1;
    }
    return 0;
}



int check_string_number(string liczba){
    for(int i =0 ; i<liczba.length(); i++){
        if((int)liczba[i] < (int)'0' || (int)liczba[i] > (int)'9'){
            cout << "Enter incorect information. You can olny use numbers 0-9 \n";
            return 1;
        }  
    }
    return 0;
}
