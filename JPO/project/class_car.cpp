
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
//#include "class_car.h"
using namespace std;

class car{
    private:
        string marka;
        string model;
        string rocznik; // czhyba lepiej string bo i tak będziemy czytać z pliku 
        string cena;
    public:

    void print(){
        cout << "marka: " << marka << "    model: " << model  <<"    rocznik: " << rocznik << "    cena (za dzien): " << cena << " zl"<<endl ;
    }

    car(string marka_ , string model_ , string rocznik_ , string cena_){
        model = model_;
        marka = marka_;
        rocznik = rocznik_;
        cena = cena_;
    }

// ------------- gettery które mogą być potrzebne ------------------
    string get_cena(){
        return cena;
    }
    string to_string(){
        string buffor = "marka: ";

        buffor.append(marka);
        buffor.append("$");

        buffor.append(" model: ");
        buffor.append(model);
        buffor.append("$");

        buffor.append(" rok: ");
        buffor.append(rocznik);

        buffor.append(" cena: ");
        buffor.append(cena);
        buffor.append("$");

        return buffor;
    }


};


class rent_car :public car{
    private:
        string time_to_end;
        string time_to_start;

    public:
        rent_car(string marka_ , string model_ , string rocznik_ ,string cena_, string end, string start) :car(marka_,model_,rocznik_,cena_){
            time_to_end = end;
            time_to_start = start;
        }

        void oblicz_cene(int x){ //wylicz cene samochodu za wyporzyczenie na X dni
            cout << "cena z wyporzyczenia na " << x << " dni to: " << stof(get_cena())*x << " zl\n";
        }
        void print(){
            car::print();
            cout << "start: " << time_to_start << "   stop: " << time_to_end << endl; 
        }
        string to_string(){
            string buffor = car::to_string();

            buffor.append(" od: ");
            buffor.append(time_to_start);

            buffor.append(" do: ");
            buffor.append(time_to_end);

            return buffor;
        }


};