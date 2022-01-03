
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
#include "car_rent.h"

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
      cout << "\n********** Enter the comend: **********\n";
      getline(cin,komenda);
      if(komenda == "help"){
         system("cls");
         cout << "available commands:\n";
         cout << "1) add - add a new car\n";
         cout << "2) delete' - to delete a car\n";
         cout << "3) print - print information about cars\n";
         cout << "4) rent\n";
         cout << "5) exit\n";
         cout << "6) clear- clear terminal \n";
         cout << "7) help\n**************************************\n";
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
            cout << "welcome to the display function \n";
            cout << "Enter one of the command below and follow the instructions \n";
            cout << "1) all - print information about all cars\n";
            cout << "2) ID - enter car ID to print information about this car (use format XXXX)\n";
            cout << "3) advance - detailed search\n";
            cout << "4) exit - to exit\n";
            cout << "5) help - to print commands \n";
         while(1){
            cout << "\n######## Enter the search/print command ########\n";
            getline(cin,komenda);
            if(komenda == "all"){
               system("cls");
               for(auto print_car: samochody){
                  print_car.print();
               }
            }
            else if(komenda == "ID"){
               system("cls");
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
               cout <<"1) mark - to search make of car\n";
               cout <<"2) model - to search car model\n";
               cout <<"3) year - to search year of production\n";
               cout <<"4) price - to search a price\n";
               cout <<"5) exit\n";
               cout <<"6) help\n";
               while(1){
                  cout << "######## Enter the advance search key word ########\n";
                  string search_for;
                  bool car_does_not_exist = true;
                  getline(cin,buffor);
                  if(buffor == "mark"){
                     system("cls");
                     cout << "enter the make of car (use only use lowercase letters)\n";
                     getline(cin,search_for);
                     for(auto search_in_samochody: samochody){
                        if(search_in_samochody.get_marka() == search_for){
                           search_in_samochody.print();
                           car_does_not_exist = false;
                        }
                     }
                     if(car_does_not_exist)
                        cout << "make of car: "<<search_for<< " does not exist in our liblary";
                  }
                  else if(buffor == "model"){
                     system("cls");
                     cout << "enter the car model (use only use lowercase letters)\n";
                     getline(cin,search_for);
                     for(auto search_in_samochody: samochody){
                        if(search_in_samochody.get_model() == search_for){
                           search_in_samochody.print();
                           car_does_not_exist = false;
                        }
                     }
                     if(car_does_not_exist)
                        cout << "Car model: "<<search_for<< " does not exist in our liblary";
                  }
                  else if(buffor == "year"){
                     system("cls");
                     cout << "enter year of production\n" ;
                     getline(cin,search_for);
                     if(check_year(search_for))
                        continue;
                     for(auto search_in_samochody: samochody){
                        if(search_in_samochody.get_rok() == search_for){
                           search_in_samochody.print();
                           car_does_not_exist = false;
                        }
                     }
                     if(car_does_not_exist)
                        cout << "car produced in the year: "<<search_for<< " does not exist in our liblary";
                  }
                  else if(buffor == "price"){
                     system("cls");
                     cout << "enter lower price\n" ;
                     string lower_price;
                     string high_price;
                     getline(cin,lower_price);
                     if(check_string_number(lower_price))
                        continue;

                     cout << "enter highest price\n" ; 
                     getline(cin,high_price);
                     if(check_string_number(high_price))
                        continue;

                     for(auto search_in_samochody: samochody){
                        if(stoi(search_in_samochody.get_cena()) >= stoi(lower_price) && stoi(search_in_samochody.get_cena()) <= stoi(high_price)){
                           search_in_samochody.print();
                           car_does_not_exist = false;
                        }
                     }
                     if(car_does_not_exist)
                        cout << "Car with a price between the lowest and the highest ( "<< lower_price<<"-"<<high_price<< " ) does not exist in our liblary";
                  }
                  else if(buffor == "exit"){
                     system("cls");
                     break;
                  }
                  else if(buffor == "help"){
                     system("cls");
                     cout <<"##### Advance serching ##### \n";
                     cout <<"1) mark - to search make of car\n";
                     cout <<"2) model - to search car model\n";
                     cout <<"3) year - to search year of production\n";
                     cout <<"4) price - to search a price\n";
                     cout <<"5) exit\n";
                     cout <<"6) help\n";
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
            system("cls");
            cout << "welcome to the display function \n";
            cout << "Enter one of the command below and follow the instructions \n";
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
            cout << "Are you sure y/n\n";
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
         string time_stop = to_string(ltm->tm_mday)+"."+to_string(1 + (ltm->tm_mon))+"."+to_string(1900+ (ltm->tm_year));
         if(rent_function(time_stop)){
            cout <<"unexpected error in function 'rent'\n";
         }
      }
      else if(komenda == "clear"){
         system("cls");
         continue;
      }
      else{
         cout << "incorect comend\n";
      }
   }   
}