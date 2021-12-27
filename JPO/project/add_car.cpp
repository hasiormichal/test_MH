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
    system("cls");
    while(1){
        cout << "\n----- Enter the car ID in the format 'XXXX' in range 0000 - 9999 -----\n";
        cout << "Enter 'exit' to abandon adding the car \n";
        getline(cin,buffor);
        if(buffor == "exit"){
            return 1;
        }
        if(buffor.length() != 4){
            cout << "Bad ID format, use XXXX\n";
            continue;
        }

        if(check_string_number(buffor)){
            cout << "Bad ID, incorect char\n";
            continue;
        }
        bool flag = false;
        for(auto check_id: all_id){
            if(check_id == buffor){
                cout << "This ID is already used\n";
                flag = true;
                break;
            }
        }

        if(flag) // do it, because ID is already used
            continue;

        string cala_nazwa = "id: ";
        cala_nazwa.append(buffor);




        cout <<  "Enter the make of a car (use only use lowercase letters)\n";
        getline(cin,buffor);
        if(buffor.empty()){
            cout<<"You can't enter empty make of car\n";
            continue;
        }
        cala_nazwa.append(" $marka: ");
        cala_nazwa.append(buffor);




        cout << "Enter the model (use only use lowercase letters) \n";
        getline(cin,buffor);
        if(buffor.empty()){
            cout<<"You can't enter empty model\n";
            continue;
        }
        cala_nazwa.append(" $model: ");
        cala_nazwa.append(buffor);
        


        cout << "Enter year of production\n";
        getline(cin,buffor);
        if(check_string_number(buffor)){
            cout << "Bad year of production, incorect char\n";
            continue;
        }
        if(stoi(buffor) <= 1900 || stoi(buffor) >= 2050){
            cout << "incorect date\n";
            continue;
        }
        cala_nazwa.append(" $rok: ");
        cala_nazwa.append(buffor);



        cout << "Enter price for a one day \n";
        getline(cin,buffor);
        if(check_string_number(buffor)){
            cout << "Bad price, incorect char\n";
            continue;
        }
        cala_nazwa.append(" $cena: ");
        cala_nazwa.append(buffor);





        cala_nazwa.append(" $od: 00.00.0000  $do: 00.00.0000");
        buffor = cala_nazwa; 
        rent_car test = create_class(buffor);
        dodaj_do_klas.push_back(test);
        return 0;
    }    
}

int check_string_number(string liczba){
    for(int i =0 ; i<liczba.length(); i++){
        if((int)liczba[i] < (int)'0' || (int)liczba[i] > (int)'9'){
            return 1;
        }  
    }
    return 0; 
}

