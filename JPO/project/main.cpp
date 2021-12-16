
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

using namespace std;

int main(){
   vector <string> odczytany_plik;
   odczytany_plik = read_from_file("plik.txt");
   vector <class rent_car> samochody;
   samochody = create_classes(odczytany_plik);
   vector <string> all_id = create_all_id(samochody);

   time_t now;
   tm *ltm = localtime(&now);

   string komenda = {};

   while(1){  //głowne pętle programu odpowiadająca za sterowanie
      getline(cin,komenda);
      

      if(komenda == "add"){
         cout << "add\n";
         if(add_car(samochody,all_id)){
            cout << "zle id\n";
         }
         else{
            cout << "dodano nowy samochod\n";
         }
      }



      else if(komenda == "print"){
         samochody[1].print();
      }



      else if (komenda == "koniec"){
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

      else if(komenda == "wyporzycz"){
         string time_start;
         string time_stop;
         string car_id;

         cout << "Podaj id wyporzyczanego samochodu\n";
         getline(cin,car_id);

         cout << "podaj date od kiedy samochud bedzie wyporzyczony (w formacie dd.mm.rrr):\n";
         getline(cin,time_start);

         cout << "podaj date do kiedy bedzie wyporzyczony (w formacie dd.mm.rrr):\n";
         getline(cin,time_stop);

         for(auto it=samochody.begin(); it !=samochody.end();  it++){
            if((*it).get_id() == car_id){
               (*it).wyporzycz(time_stop,time_start);

               //drugie pytanie??
               //nwm dlaczego nie działa nadpisywanie gdy mamy for(auto asda:samochody)
               break;
            }
         }
      }

      else{
         cout << "zla komenda\n";
      }
   }   
}