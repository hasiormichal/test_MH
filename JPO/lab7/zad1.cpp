#include <iostream>
#include <string>
#include <vector>
//#include <map>
using namespace std;

class person{
    private:
        string imie{};
        string nazwisko{};
        string pesel{};  

    public:
        person (string imie_="Jan" , string nazwisko_="Kowalski", string pesel_= "0"){
            imie = imie_;
            nazwisko = nazwisko_;
            pesel = pesel_;
        }
//-------------getery--------------
        string get_imie(){
            return imie;
        }

        string get_nazwisko(){
            return nazwisko;
        }

        string get_pesel(){
            return pesel;
        }
//-----------setry -------------
        void set_imie(string imie_){
            imie = imie_;
        }
        void set_nazwisko(string nazwisko_){
            nazwisko = nazwisko_;
        }
        void set_pesel(string pesel_){
            pesel = pesel_;
        }        

        string to_string(){
            return imie + " " + nazwisko + " " + pesel;
        }

};

class student :public person{
    private:
        string indeks;
        string kierunek;
    public:

        student(string imie_="Jan" , string nazwisko_="Kowalski", string pesel_="0" ,string indeks_ = "0" , string kierunek_ = "Brak" ) 
        :person (imie_,nazwisko_,pesel_) {
            indeks = indeks_;
            kierunek = kierunek_;
        }

        string get_indeks(){
            return indeks;
        }
        string get_kierunek(){
            return kierunek;
        }

        string to_string(){
            
           // return get_imie() + " " + nazwisko + " " + pesel + " " + indeks + " " + kierunek;
           return person::to_string() + " "+ indeks + " " + kierunek;
           /*
            string inf = person::to_string();
            inf = inf + " " + indeks + " " + kierunek;

            return inf;*/
        }
};


int main(){
    person jeden;
    student dwa;

    vector <class person> EiT;
    for(int i=0 ; i<3 ; i++)
        EiT.push_back(jeden);

    EiT.push_back(dwa);
    for(int i=0 ; i<4 ; i++)
        cout << EiT[i].to_string() <<endl;
        //cout << jeden 

}