#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

//#include "class_car.cpp"  //nwm co z tym includem czy może byc
#include "create_class.h"
#include "global.h"
using namespace std;

void create_classes(vector<string> lista_samochodow){
    string id = {};
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
    for (auto obiekty: lista_samochodow ) { 

        poz1 = obiekty.find("$id:");
        id = obiekty.substr(poz1+id_length,4);

        poz1 = obiekty.find("$marka:");
        poz2 = obiekty.find("$model",0);
        marka = obiekty.substr(poz1+marka_lenght,poz2-(poz1+marka_lenght+1));

        poz1 = obiekty.find("$model:");
        poz2 = obiekty.find("$rok",poz2+1);
        model = obiekty.substr(poz1+model_lenght,poz2-(poz1+model_lenght+1));

        poz1 = obiekty.find("$rok:");
        rocznik = obiekty.substr(poz1+rok_lenght,4);

        poz1 = obiekty.find("$cena:");
        poz2 = obiekty.find("$od",poz2+1);
        cena = obiekty.substr(poz1+cena_lenght,poz2-(poz1+cena_lenght+1));

        poz1 = obiekty.find("$od:");
        start = obiekty.substr(poz1+od_lenght,10);

        poz1 = obiekty.find("$do:");
        koniec = obiekty.substr(poz1+do_lenght,10);

        samochody.push_back(rent_car(id,marka,model,rocznik,cena,start,koniec));

    }

}


class rent_car create_class(string obiekty){
    string id = {};
    string marka={};
    string model = {};
    string rocznik = {};
    string cena = {};
    string start = {};
    string koniec = {};
    size_t poz1;
    size_t poz2;
    //cout << obiekty << endl;

    poz1 = obiekty.find("$id:");
    id = obiekty.substr(poz1+id_length,4);

    poz1 = obiekty.find("$marka:");
    poz2 = obiekty.find("$model",0);
    marka = obiekty.substr(poz1+marka_lenght,poz2-(poz1+marka_lenght+1));

    poz1 = obiekty.find("$model:");
    poz2 = obiekty.find("$rok",poz2+1);
    model = obiekty.substr(poz1+model_lenght,poz2-(poz1+model_lenght+1));

    poz1 = obiekty.find("$rok:");
    rocznik = obiekty.substr(poz1+rok_lenght,4);

    poz1 = obiekty.find("$cena:");
    poz2 = obiekty.find("$od",poz2+1);
    cena = obiekty.substr(poz1+cena_lenght,poz2-(poz1+cena_lenght+1));

    poz1 = obiekty.find("$od:");
    start = obiekty.substr(poz1+od_lenght,10);

    poz1 = obiekty.find("$do:");
    koniec = obiekty.substr(poz1+do_lenght,10);

    rent_car new_class(id,marka,model,rocznik,cena,start,koniec);
    return new_class;
}

void create_all_id () {
    // to store all "id" 
    // this vectror will bu used to check if user create new car with reserved id

    for(auto temporary: samochody){
        all_id.push_back(temporary.get_id());
    }
}