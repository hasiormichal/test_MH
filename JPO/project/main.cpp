
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//to read date
#include <ctime>


//#include "class_car.cpp"
#include "read_from_file.h"
#include "create_class.h"
#include "add_car.h"
#include "save_data.h"
#include "check_time.h"
#include "global.h"
#include "check_functions.h"

using namespace std;

vector <class rent_car> samochody;
vector <string> all_id;


int main(){
   vector <string> odczytany_plik;
   odczytany_plik = read_from_file("plik.txt");
   create_classes(odczytany_plik);
   create_all_id();

   time_t now;
   time(&now);
   tm *ltm = localtime(&now);

   system("cls");
   cout << "-----welcome in Car rant simulator-----\n";
   cout << "available commands:\n";
   cout << "add - add a new car\n";
   cout << "print - print som informations\n";
   cout << "rent\n";
   cout << "exit\n";
   cout << "help\n";
   cout << "clear- clear terminal \n";

   string komenda = {};

   while(1){  //głowne pętle programu odpowiadająca za sterowanie
      cout << "\n***** Enter the comend: *****\n";
      getline(cin,komenda);
      if(komenda == "help"){
         cout << "available commands:\n";
         cout << "1) add - add a new car\n";
         cout << "2) print \n";
         cout << "3) rent\n";
         cout << "4) exit\n";
         cout << "6) help\n-----------------------\n";
      }

      else if(komenda == "add"){
         int zmienna = add_car();
         if(zmienna == 1){
            cout << "The car has not been added\n";
         }
         else if(zmienna == 0){
            cout << "Add a new car successfully\n";
         }
         else{
            cout << "Error - after function 'add'\n";
         }
      }
      else if(komenda == "delete"){
         if(delete_car()){
            cout << "the car wasn't removed\n";
            continue;
         }
         cout <<  "the car has been removed\n";
      }
      else if(komenda == "print"){
            system("cls");
            cout << "1) all - print information about all cars\n";
            cout << "2) ID - enter car ID to print information about this car (use format XXXX)\n";
            cout << "3) advance - detailed search\n";
            cout << "4) exit - to exit\n";
            cout << "5) help - to print commands \n";
         while(1){
            cout << "##### Enter the search/print command\n";
            getline(cin,komenda);
            if(komenda == "all"){
               for(auto print_car: samochody){
                  print_car.print();
               }
            }
            else if(komenda == "ID"){
               cout << "Enter car ID\n";
               getline(cin,komenda);
               if(komenda.length() != 4){
                  cout << "Bad ID format, use XXXX\n";
                     continue;
               }

               if(check_string_number(komenda)){
                  cout << "Bad ID, incorect char\n";
                  continue;
               }
               for(auto id_car : samochody){
                  if(id_car.get_id() == komenda)
                     id_car.print();
               }
            }
            else if(komenda == "advance"){
               string buffor ={};
               system("cls");
               cout <<"##### Advance serching ##### \n";
               cout <<"'mark' - to search make of car\n";
               cout <<"'model' - to search car model\n";
               cout <<"'year' - to search year of production\n";
               cout <<"'price' - to search a price\n";
               cout << "exit\n";
               cout << "help\n";
               while(1){
                  cout << "##### Enter the advance search command\n";
                  getline(cin,buffor);
                  if(buffor == "mark"){
                     cout << "enter the make of car (use only use lowercase letters)\n";
                  }
                  else if(buffor == "model"){
                     cout << "enter the car model (use only use lowercase letters)\n";
                  }
                  else if(buffor == "year"){
                     cout << "enter year of production\n" ;
                  }
                  else if(buffor == "price"){
                     cout << "enter the price\n" ;
                  }
                  else if(buffor == "exit"){
                     break;
                  }
                  else if(buffor == "help"){
                     cout <<"##### Advance serching ##### \n";
                     cout <<"'mark' - to search make of car\n";
                     cout <<"'model' - to search car model\n";
                     cout <<"'year' - to search year of production\n";
                     cout <<"'price' - to search a price\n";
                     cout << "exit\n";
                     cout << "help\n";
                  }
                  else{
                     cout <<"invalid komend\n";
                     continue;
                  }
               }
            }
            else if(komenda == "exit"){
               system("cls");
               break;
            }
            else if(komenda == "help"){
               cout << "1) all - print information about all cars\n";
               cout << "2) ID - enter car ID to print information about this car (use format XXXX)\n";
               cout << "3) advance - detailed search\n";
               cout << "4) exit - to exit\n";
               cout << "5) help - to print commands \n";
            }
            else{
               cout << "incorect command\n";
            }
         }
      }



      else if (komenda == "exit"){
         // todo: ewentualna funkcja zapisująco funkcja zapisująca
      
         string wyjscie;
         while (1){
            cout << "Czy napewno y/n\n";
            cin >> wyjscie;
            if (wyjscie == "y"){
               system("cls");
               save_data();
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
            cout << "Podaj ID wyporzyczanego samochodu\nlub 'exit' aby wyjsc \n";
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
                  (*it).oblicz_cene(number_of_days_in_between(time_start,time_stop));
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