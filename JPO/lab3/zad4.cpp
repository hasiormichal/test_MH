#include <iostream>
#include <string>

using namespace std;


int main(int argc, char **argv) {
    string wiersz1{},wiersz2{};
    //pobieranie danych
    cout << "podaj pierwszy wyraz" << endl;
    getline(cin , wiersz1);
    cout << "podaj drugi wyraz" << endl;
    getline(cin , wiersz2);

    //porównanie rozmiarów
    if(wiersz1.length() != wiersz2.length()){
        cout << " ciangi maja rozne rozmiary" << endl;
        exit;
    }    
    else{
         //wpisuje dwa razy ten sam ciag do jednej zmiennej 
         // otrzymam w ten sposób cykliczne przesuniecie   
         // które znajduje się gdziś w srodku tego stringa
         // na koncu znajduje find'em czy drogi wyraz zawiera sie w stworzonej zmiennej
        string bufor = wiersz1 + wiersz1;      
        size_t name_poz = bufor.find(wiersz2);    
        if( name_poz == string::npos )          
            cout << "podane wyrazy nie sa cykliczne" << endl;
        else
            cout << wiersz1 << " oraz "<< wiersz2 << " sa cykliczne" << endl;
    }

}