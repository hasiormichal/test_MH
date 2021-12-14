
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


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

    string komenda = {};

   while(1){  //głowne pętle programu odpowiadająca za sterowanie
      getline(cin,komenda);
      
      if(komenda == "add"){
         cout << "add\n";
         add_car(samochody);
         cout << "dodano nowy samochod\n";
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
      else{
         cout << "zla komenda\n";
      }
   }   
}