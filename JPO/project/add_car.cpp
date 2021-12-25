#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include "class_car.cpp"  //nwm co z tym includem czy może byc
#include "add_car.h"
#include "create_class.h"
using namespace std;

int add_car(vector <class rent_car> &dodaj_do_klas , vector <string> all_id){
    //dodawanie będzie polegało na wyświetlaniu informacji i wpisywaniu po kolei informacji  
    string buffor = {};
    system("clear");
    cout << "Enter the car ID in the format 'XXXX'\n";
    getline(cin,buffor);

    for(auto check_id: all_id){
        if(check_id == buffor){
            return 1; //return if ID already exist
        }
    }

    string cala_nazwa = "id: ";
    cala_nazwa.append(buffor);

    cout <<  "Enter the make of a car\n";
    getline(cin,buffor);
    cala_nazwa.append(" marka: ");
    cala_nazwa.append(buffor);
    cala_nazwa.append("$");

    cout << "Enter the model\n";
    getline(cin,buffor);
    cala_nazwa.append(" model: ");
    cala_nazwa.append(buffor);
    cala_nazwa.append("$");

    cout << "Enter year of production\n";
    getline(cin,buffor);
    cala_nazwa.append(" rok: ");
    cala_nazwa.append(buffor);

    cout << "Enter price for a one day \n";
    getline(cin,buffor);
    cala_nazwa.append(" cena: ");
    cala_nazwa.append(buffor);
    cala_nazwa.append("$");

    cala_nazwa.append(" od: 00.00.0000  do: 00.00.0000");
    buffor = cala_nazwa; 
    rent_car test = create_class(buffor);
    dodaj_do_klas.push_back(test);
    return 0;
}