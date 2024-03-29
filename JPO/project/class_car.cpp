
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include <ctime>

//#include "class_car.h"
using namespace std;

class car{
    private:
        string id;
        string marka;
        string model;
        string rocznik; // czhyba lepiej string bo i tak będziemy czytać z pliku 
        string cena;
    public:

    void print(){
        cout << "ID: "<< id << "    The car brand: " << marka << "    Model: " << model  <<"    Year of production: " << rocznik << "    price (per day): " << cena << " zl"<<endl ;
    }

    car(string id_,string marka_ , string model_ , string rocznik_ , string cena_){
        id = id_;
        model = model_;
        marka = marka_;
        rocznik = rocznik_;
        cena = cena_;
    }

// ------------- gettery które mogą być potrzebne ------------------
    string get_cena(){
        return cena;
    }
    string get_id(){
        return id;
    }
    string class_to_string(){
        string buffor = "$id: ";

        buffor.append(id);

        buffor.append(" $marka: ");
        buffor.append(marka);

        buffor.append(" $model: ");
        buffor.append(model);

        buffor.append(" $rok: ");
        buffor.append(rocznik);

        buffor.append(" $cena: ");
        buffor.append(cena);

        return buffor;
    }
    string get_marka(){
        return marka;
    }

    string get_model(){
        return model;
    }

    string get_rok(){
        return rocznik;
    }
};


class rent_car :public car{
    private:
        string time_to_end;
        string time_to_start;

    public:
        rent_car(string id_, string marka_ , string model_ , string rocznik_ ,string cena_, string start, string end) :car(id_,marka_,model_,rocznik_,cena_){
            time_to_end = end;
            time_to_start = start;
        }

        void oblicz_cene(int x){ //wylicz cene samochodu za wyporzyczenie na X dni
            cout << "Rental price for " << x << " days: " << stof(get_cena())*x << " zl\n";
        }
        void print(){
            car::print();
            cout << "start of rent: " << time_to_start << "   end of rent: " << time_to_end << endl; 
        }
        string class_to_string(){
            string buffor = car::class_to_string();

            buffor.append(" $od: ");
            buffor.append(time_to_start);

            buffor.append(" $do: ");
            buffor.append(time_to_end);

            return buffor;
        }

        void set_stop_time(string stop_time){
            time_to_end = stop_time;
        }


        int wyporzycz(string data ,string data_start){
            if( time_to_end == "00.00.0000"){
                time_to_end = data;
                time_to_start = data_start;
                cout << "Your car has been rented:\n";
                print();
                return 0;
                 //cout << "od dnia: "<<time_to_start<< "    do dnia: "<<time_to_end<<endl;
            }
            else{
                cout << "The selected car is already reserved for a period\n";
                cout << "start of rent: "<<time_to_start<< "   end of rent: "<<time_to_end<<endl;
                return 1;
            }
        }

        void set_date(){
            time_to_end = "00.00.0000";
            time_to_start = "00.00.0000";
        }



};