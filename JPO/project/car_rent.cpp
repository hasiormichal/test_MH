#include <string>
#include <iostream>
#include <vector>

#include "car_rent.h"
#include "global.h"
#include "check_time.h" 
#include "check_functions.h"


using namespace std;

int rent_function(string time_stop){
    string time_start;
    string car_id;
    string pomocnicza = "---";
    system("cls");
    //
    cout << "+++++ welcome to the rent_car function +++++\n";
    cout << "Enter one of the command below and follow the instructions \n";
    cout << "1) rent - rent a car\n";
    cout << "2) free - release reservations\n";
    cout << "3) exit\n";
    cout << "4) help\n";
    while(1){
        cout <<"+++++++++++ Enter the 'rent' command +++++++++++\n";
        getline(cin,pomocnicza);
        if(pomocnicza == "rent"){
            system("cls");
            while ( pomocnicza != "exit"){
                cout << "Please enter the ID of the rental car or 'exit' to exit\n";
                getline(cin,car_id);
                if(car_id == "exit")
                    break;
                if(check_ID(car_id));
                    continue;

                cout << "enter the start date of the rent (in the format dd.mm.yyyy) or 'exit' to exit\n";
                getline(cin,time_start);
                if(time_start == "exit")
                    break;
                if(check_calendary(time_start))
                    continue; //bład -> wpisana date jest nie istnieje 
                if(check_date(time_stop , time_start))
                    continue;  //wystąpił bład
        
                cout << "enter the end date of the rent (in the format dd.mm.yyyy) or 'exit' to exit\n";
                getline(cin,time_stop);
                if(time_stop == "exit");
                    break;
                if(check_calendary(time_start))
                    continue; //bład -> wpisana date jest nie istnieje 
                if(check_date(time_start , time_stop))
                    continue;

                for(auto it=samochody.begin(); it !=samochody.end();  it++){
                if((*it).get_id() == car_id){
                    (*it).wyporzycz(time_stop,time_start);
                    (*it).oblicz_cene(number_of_days_in_between(time_start,time_stop)+1);
                    //drugie pytanie??
                    //nwm dlaczego nie działa nadpisywanie gdy mamy for(auto asda:samochody)
                    break;
                    }
                }     
            }
            break;
        } // end of cunction 'rent'

        else if (pomocnicza == "rent_free"){
            system("cls");
            while ( pomocnicza != "exit"){
                cout << "Please enter the ID of the rental car or 'exit' to exit\n\n";
                getline(cin,car_id);
                if(car_id == "exit")
                    break;
                if(check_ID(car_id))
                    continue;
                bool rent_free = true;    
                for(auto it=samochody.begin(); it <=samochody.end();  it++){
                    if((*it).get_id() == car_id){
                        (*it).set_date();
                        cout << "The release of the booking was successful\n";
                        rent_free = false;
                        break;
                    }
                }
                if(rent_free){
                    cout << "Car ID " << car_id << " does not exist\n";
                    continue;   
                }
            }
        } // end of cunction 'rent_free'

        else if (pomocnicza == "help"){
            cout << "+++++ welcome to the rent_car function +++++\n";
            cout << "Enter one of the command below and follow the instructions \n";
            cout << "1) rent - rent a car\n";
            cout << "2) free - release reservations\n";
            cout << "3) exit\n";
            cout << "4) help\n";
        }
        else if (pomocnicza == "exit"){
            return 0;
        }
        else{
            cout << "Enter invalid commend\n";
            continue;
        }
    }
    return 1;
}