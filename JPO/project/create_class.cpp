#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>



#include "class_car.h"
#include "create_class.h"
using namespace std;

void create_class(vector<string> &obiekty){
    string marka={};
    string model = {};
    string rocznik = {};
    string cena = {};
    string start = {};
    string koniec = {};
    size_t poz1;
    size_t poz2;
// todo: zastanowić się czy jest sens wpisywanie tego jako obiek klasy ?? jak wiedzić potem w programie że chcemy odwoalć się do danego elemntu klasy
//
// poniżej funkcja która powinna poprawnie odczytać do zmiennych odpiwenie dane
    for (auto pentla: obiekty ) {  
        poz1 = pentla.find("marka:");
        poz2 = pentla.find("$");
        marka = pentla[poz1+marka_lenght,poz2];

        poz1 = pentla.find("model:");
        poz2 = pentla.find("$",poz2+1);
        model = pentla[poz1+model_lenght,poz2];

        poz1 = pentla.find("rok:");
        rocznik = pentla[poz1+rok_lenght,poz1+rok_lenght+4];

        poz1 = pentla.find("cena:");
        poz2 = pentla.find("$",poz2+1);
        cena = pentla[poz1+cena_lenght,poz2];

        poz1 = pentla.find("od:");
        start = pentla[poz1+od_lenght,poz1+rok_lenght+10];

        poz1 = pentla.find("do:");
        koniec = pentla[poz1+do_lenght,poz1+rok_lenght+10];

        rent_car ford (marka , model , rocznik , cena , start , koniec);
    }
    rent_car ford (marka , model , rocznik , cena , start , koniec);
    ford.print();

}