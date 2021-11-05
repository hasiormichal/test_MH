#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
//#include <random>
//#include <chrono>
#include <map>
using namespace std;


int main(){

map <string,size_t> ksiazka;

ksiazka["policja"] = 997;
ksiazka["pogotowie"] = 999;
ksiazka["alarmowy"] = 112;
const string exit = "exit";
string nazwa{};
string getnumer{};
size_t numer;
while(1){

    cout << "podaj imie" << endl;
    getline(cin,nazwa);
    if(nazwa == exit)
        return 0;
    if(ksiazka.find(nazwa) == ksiazka.end()){
        cout << "Key not exist!" << endl;
        cout << "podaj numer" << endl;
        getline(cin,getnumer);
        numer = stoull(getnumer);
        ksiazka[nazwa]=numer;
        cout << "dodano nowy numer"<<endl;
    }else{
        cout << nazwa <<  " - " << ksiazka[nazwa]  << endl;
    }
}

}