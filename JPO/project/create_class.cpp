#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>



#include "class_car.cpp"  //nwm co z tym includem czy może byc
#include "create_class.h"
using namespace std;

void create_class(vector<string> obiekty){
    string marka={};
    string model = {};
    string rocznik = {};
    string cena = {};
    string start = {};
    string koniec = {};
    size_t poz1;
    size_t poz2;

    vector <class rent_car> samochody;
// todo: zastanowić się czy jest sens wpisywanie tego jako obiek klasy ?? jak wiedzić potem w programie że chcemy odwoalć się do danego elemntu klasy
//
// poniżej funkcja która powinna poprawnie odczytać do zmiennych odpiwenie dane
    for (auto pentla: obiekty ) { 
        poz1 = pentla.find("marka:");
        poz2 = pentla.find("$",0);
        marka = pentla.substr(poz1+marka_lenght,poz2-(poz1+marka_lenght));

        poz1 = pentla.find("model:");
        poz2 = pentla.find("$",poz2+1);
        model = pentla.substr(poz1+model_lenght,poz2-(poz1+model_lenght));

        poz1 = pentla.find("rok:");
        rocznik = pentla.substr(poz1+rok_lenght,4);

        poz1 = pentla.find("cena:");
        poz2 = pentla.find("$",poz2+1);
        cena = pentla.substr(poz1+cena_lenght,poz2-(poz1+cena_lenght));

        poz1 = pentla.find("od:");
        start = pentla.substr(poz1+od_lenght,10);

        poz1 = pentla.find("do:");
        koniec = pentla.substr(poz1+do_lenght,10);

        samochody.push_back(rent_car(marka,model,rocznik,cena,start,koniec));

    }
    samochody[0].print();
    samochody[1].print();

}