#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){
    srand(time(NULL));
    int a,i=0;
    int x = rand()%101;
    while(i<5){
        cout << "zagadnij wylosowana liczbe" << endl;
        cin >> a;
        if(a == x){
            cout << "zgadles ;D" << endl;
            return(0);
        }
        else if(a < x){
            cout << "podales mniejsza liczbe" << endl;
            i++;
            continue;
        }
        else{
            cout << "podales wieksza liczbe" << endl;
            i++;
        }
    }
    cout << "przekroczyles ilosc prob" << endl;
    cout << "wylosowana liczba to x = " << x << endl;
    exit(0);
}