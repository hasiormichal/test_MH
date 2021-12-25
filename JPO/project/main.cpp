
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//to read date
#include <ctime>


#include "class_car.cpp"
#include "read_from_file.h"
#include "create_class.h"
#include "add_car.h"
#include "save_data.h"
#include "check_time.h"

using namespace std;

int main(){
   vector <string> odczytany_plik;
   odczytany_plik = read_from_file("plik.txt");
   vector <class rent_car> samochody;
   samochody = create_classes(odczytany_plik);
   vector <string> all_id = create_all_id(samochody);

   time_t now;
   time(&now);
   tm *ltm = localtime(&now);

   system("clear");
   cout << "-----welcome in Car rant simulator-----\n";
   cout << "available commands:\n";
   cout << "add - add a new car\n";
   cout << "print - print som informations\n";
   cout << "rent\n";
   cout << "exit\n";
   cout << "help\n";
   cout << "clear - clear terminal \n";

   string komenda = {};

   while(1){  //głowne pętle programu odpowiadająca za sterowanie
      getline(cin,komenda);
      cout << "enter the comend:\n";
      if(komenda == "help"){
         cout << "available commands:\n";
         cout << "add - add a new car\n";
         cout << "print \n";
         cout << "rent\n";
         cout << "exit\n";
         cout << "help\n";
      }

      else if(komenda == "add"){
         if(add_car(samochody,all_id)){
            cout << "This ID is already used\n";
         }
         else{
            cout << "Add a new car successfully\n";
         }
      }

      else if(komenda == "print"){ // to do  additionam menu  print all cars, print car if given is ID 
         system("clear");
         cout << "all - print dinformation obout all cars\n";
      }



      else if (komenda == "exit"){
         // todo: ewentualna funkcja zapisująco funkcja zapisująca
      
         string wyjscie;
         while (1){
            cout << "Czy napewno y/n\n";
            cin >> wyjscie;
            if (wyjscie == "y"){
               save_data(samochody);
               return 0;
            }
            else if(wyjscie == "n"){
               break;
            }
            else{
               continue;
            }
         }
      }

      else if(komenda == "rent"){
         string time_start;
         string time_stop = to_string(ltm->tm_mday)+"."+to_string(1 + (ltm->tm_mon))+"."+to_string(1900+ (ltm->tm_year));
         string car_id;
         string pomocnicza = "---";

         while ( pomocnicza != "exit"){
            cout << "Podaj id wyporzyczanego samochodu\nlub 'exit' aby wyjsc \n";
            getline(cin,car_id);
            if(car_id == "exit")
               break;
            if( car_id.length() != 4){
               cout << "zle wspisane id. powinno byc w formacie -> XXXX\nlub 'exit' aby wyjsc";
               continue;
            }


            cout << "podaj date od kiedy samochud bedzie wyporzyczony (w formacie dd.mm.rrr):\nlub 'exit' aby wyjsc\n";
            getline(cin,time_start);
            if(time_start == "exit")
               break;
            if(check_calendary(time_start))
               continue; //bład -> wpisana date jest nie istnieje 
            if(check_date(time_stop , time_start))
               continue;  //wystąpił bład
      
            cout << "podaj date do kiedy bedzie wyporzyczony (w formacie dd.mm.rrr):\nlub 'exit' aby wyjsc\n";
            getline(cin,time_stop);
            if(time_stop == "exit");
            if(check_calendary(time_start))
               continue; //bład -> wpisana date jest nie istnieje 
            if(check_date(time_start , time_stop))
               continue;

            for(auto it=samochody.begin(); it !=samochody.end();  it++){
               if((*it).get_id() == car_id){
                  (*it).wyporzycz(time_stop,time_start);

                  //drugie pytanie??
                  //nwm dlaczego nie działa nadpisywanie gdy mamy for(auto asda:samochody)
                  break;
               }
               
            }
            break;
         }
      }

      else{
         cout << "incorect comend\n";
      }
   }   
}