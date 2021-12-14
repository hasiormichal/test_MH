#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include "class_car.cpp"  //nwm co z tym includem czy może byc
#include "add_car.h"
#include "create_class.h"
using namespace std;

void add_car(vector <class rent_car> &dodaj_do_klas){
    //dodawanie będzie polegało na wyświetlaniu informacji i wpisywaniu po kolei informacji  

    string cala_nazwa = "marka: ";
    string buffor = {};

    cout <<  "Podaj marke\n";
    getline(cin,buffor);
    cala_nazwa.append(buffor);
    cala_nazwa.append("$");

    cout << "podaj model \n";
    getline(cin,buffor);
    cala_nazwa.append(" model: ");
    cala_nazwa.append(buffor);
    cala_nazwa.append("$");

    cout << "podaj rocznik \n";
    getline(cin,buffor);
    cala_nazwa.append(" rok: ");
    cala_nazwa.append(buffor);

    cout << "podaj cene \n";
    getline(cin,buffor);
    cala_nazwa.append(" cena: ");
    cala_nazwa.append(buffor);
    cala_nazwa.append("$");

    cala_nazwa.append(" od: 00.00.0000  do: 00.00.0000");
    buffor = cala_nazwa; 
    rent_car test = create_class(buffor);
    dodaj_do_klas.push_back(test);

}