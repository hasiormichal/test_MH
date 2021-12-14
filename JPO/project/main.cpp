
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#include "class_car.cpp"
#include "read_from_file.h"
#include "create_class.h"

using namespace std;

int main(){
    vector <string> odczytany_plik;
    odczytany_plik = read_from_file("plik.txt");
    vector <class rent_car> samochody;
    samochody = create_class(odczytany_plik);

    string komenda = {};

   while(1){  //głowne pętle programu odpowiadająca za sterowanie
      getline(cin,komenda);
      
      if(komenda == "a"){
         cout << "a\n";
      }
      else if(komenda == "b"){
         cout << "b\n";
      }

      else if (komenda == "koniec"){
         // todo: ewentualna funkcja zapisująco funkcja zapisująca
      
         string wyjscie;
         while (1){
            cout << "Czy napewno y/n\n";
            cin >> wyjscie;
            if (wyjscie == "y"){
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