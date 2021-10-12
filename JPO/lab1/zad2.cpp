#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;


int main(){
    double procent,wynik;
    int l_kap;
    cout << "Podaj kapitał poczatkowy" << endl;
    cin >> wynik;
    cout << "Podaj stope procentowa" << endl;
    cin >> procent;
    if (procent < 0){
        cout << "procent nie moze byc liczba ujemna" << endl;
        exit(1);
    }
    cout << "Podaj liczbe kapitalizacji" << endl;
    cin >> l_kap;

    procent = procent * 0.01; //aby z liczby rocentowej wyliczyc procent matematyczny

    for (;l_kap>0;l_kap-- ){
        wynik = wynik + procent * wynik;
    }

    cout << "wyliczony kapital = " << wynik << " zl" << endl;
    return(0);
}