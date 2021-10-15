#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a,b,c,delta,x1,x2;
     
    cout << "Podaj wspolczynnik a:" << endl;
    cin >> a;
    cout << "Podaj wspolczynnik b:" << endl;
    cin >> b;
    cout << "Podaj wspolczynnik c:" << endl;
    cin >> c;
    delta = b*b - (4*a*c);
    cout << delta << endl;
    if(delta < 0 ){
        cout << "brak rozwiazan" << endl;
        return(0);
    }
    else if(delta == 0){
        x1 = ((-1)*b)/(2*a);
        cout << "miejsce zerowe x = " << x1 << endl;
        return(0);
    }
    else{
        x1 = ((-1)*b-sqrt(delta))/(2*a);
        x2 = ((-1)*b+sqrt(delta))/(2*a);
        cout << "miejsca zerowe: x1 = " << x1 << " x2 = "<< x2 << endl;
        return(0);

    }
    return(0);
}