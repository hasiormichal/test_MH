#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

//#include "class_car.cpp"  //nwm co z tym includem czy może byc
#include "add_car.h"
#include "create_class.h"
#include "check_functions.h"
#include "global.h"
using namespace std;

int add_car(){
    //dodawanie będzie polegało na wyświetlaniu informacji i wpisywaniu po kolei informacji  
    string buffor = {};
    system("cls");
    while(1){
        cout << "\n----- Enter the car ID in the format 'XXXX' in range 0000 - 9999 -----\n";
        cout << "Enter 'exit' to abandon adding the car \n";
// ---------------------- enter ID ---------------------------------
        getline(cin,buffor);
        if(buffor == "exit"){
            return 1;
        }

        if(check_ID(buffor)){
            continue; // if user enter incorect ID 
        }
        //check ID if it is used ----------------------------
        for(auto check_id: all_id){
            if(check_id == buffor){
                cout << "This ID is already used\n";
                return 1;
            }
        }
        string cala_nazwa = "id: ";
        cala_nazwa.append(buffor);


// ---------------------- enter make of car -------------------------------
        cout <<  "Enter the make of a car (use only use lowercase letters)\n";
        getline(cin,buffor);
        if(buffor.empty()){
            cout<<"You can't enter empty make of car\n";
            continue;
        }
        cala_nazwa.append(" $marka: ");
        cala_nazwa.append(buffor);



//-----------------------------enter car model -----------------------------------
        cout << "Enter the model (use only use lowercase letters) \n";
        getline(cin,buffor);
        if(buffor.empty()){
            cout<<"You can't enter empty model\n";
            continue;
        }
        cala_nazwa.append(" $model: ");
        cala_nazwa.append(buffor);
        

//-----------------------enter year of production ---------------------------
        cout << "Enter year of production\n";
        getline(cin,buffor);
        if(check_year(buffor)){
            continue; 
        }

        cala_nazwa.append(" $rok: ");
        cala_nazwa.append(buffor);


//-------------------- enter price -------------------
        cout << "Enter price for a one day \n";
        getline(cin,buffor);
        if(check_string_number(buffor)){
            continue;
        }
        cala_nazwa.append(" $cena: ");
        cala_nazwa.append(buffor);


// -------------adding dafault information --------------

        cala_nazwa.append(" $od: 00.00.0000  $do: 00.00.0000");
        buffor = cala_nazwa; 
        rent_car test = create_class(buffor);
        all_id.push_back(test.get_id());
        samochody.push_back(test);
        return 0;
    }    
}

int delete_car(){
    string buffor = {};
    system("cls");
    while(1){
        cout << "\n----- Enter the car ID to delet. format 'XXXX' in range 0000 - 9999 -----\n";
        cout << "Enter 'exit' to abandon deleting the car \n";
// ---------------------- enter ID ---------------------------------
        getline(cin,buffor);
        if(buffor == "exit"){
            return 1;
        }
        if(check_ID(buffor)){
            continue; // if user enter incorect ID 
        }


        for (auto itt = all_id.begin(); itt != all_id.end(); itt++ ) {
            if((*itt) == buffor){
                for (auto it = samochody.begin(); it != samochody.end(); it++ ) {
                    if((*it).get_id() == buffor){
                        cout << "Are you sure to delete this car:\n";
                        (*it).print();
                        cout << "\n   y/n ??? \n";
                        char pomocnicza = getchar();
                        if(pomocnicza == 'y'){
                            samochody.erase(it);
                            all_id.erase(itt);
                            return 0;
                        }
                        else if(pomocnicza == 'n')
                            return 1;
                        else{
                            cout << "Enter incorect character\n";
                            return 1;
                        }    
                    }
                }
                cout << "error: ID exist in 'all_id' but not in 'samochody'\n";
            }
        }
        cout << "This ID does not exist \n";
    }
}