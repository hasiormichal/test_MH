#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class zesp
{
private:
    double rzeczywista;
    double urojona;
public:
    zesp(double x=0,double j=0) {
        rzeczywista = x;
        urojona = j;
    }
    //~zesp() {}

    double get_RE()const{
        return rzeczywista;
    }
    double get_IM()const{
        return urojona;
    }
    void set(double re, double im){
        rzeczywista =re;
        urojona =im;
    }
    //inkrementacja +1 do urojonych i rzeczywistych
    zesp& operator++ (){
        ++rzeczywista;
        ++urojona;
        return *this;
    }

    //post inkrementacja
    zesp operator++ (int){
        zesp temp = *this;
        ++*this;
        return temp;
    }

    zesp& operator= (const zesp& rhs){
        if(this != &rhs){
            rzeczywista = rhs.rzeczywista;
            urojona = rhs.urojona;
        }
        return *this;
    }

};


zesp operator+ (const zesp& lhs, const zesp& rhs ){
    return zesp(lhs.get_RE()+rhs.get_RE() , lhs.get_IM()+rhs.get_IM());
}

istream& operator>> (istream& in , zesp& rhs){
    double re;
    double im;
    in >> re;
    in >> im;

    rhs.set(re,im);
    return in;
}

ostream& operator<< (ostream& out, const zesp& rhs){
    if(rhs.get_IM() >=0){
        out << rhs.get_RE() << " + j" << rhs.get_IM(); 
    }
    else{
        out << rhs.get_RE() << " - j" << (rhs.get_IM() - 2*rhs.get_IM());
    }
    return out;
}

bool operator== (const zesp& lhs , const zesp& rhs ){
    return (( (lhs.get_RE() - rhs.get_RE() <= 0.01)  && (lhs.get_RE() - rhs.get_RE() >= 0.0) )||( (lhs.get_RE() - rhs.get_RE() >= -0.01)  && (lhs.get_RE() - rhs.get_RE() <= 0.0) )) && (((lhs.get_IM() - rhs.get_IM() <= 0.01) &&(lhs.get_IM() - rhs.get_IM() >= 0.0)) || (lhs.get_IM() - rhs.get_IM() >= -0.01) &&(lhs.get_IM() - rhs.get_IM() <= 0.0));
} 


int main(){

    zesp test(1,-5);
    zesp test2;
    cout << "podaj liczbe w formacie :  liczba spacja liczba"<<endl;
    cin >> test2;
    cout << test2 << endl;
    test++;
    cout << "test = " << test<<endl;
    test2 = test+test2;
    cout << "test + test2 = " << test2 <<endl;
    //cout << test << endl;

    if( test == test2){
        cout << "liczby sa rowne" << endl;
    }
    else{
        cout << "liczby nie sa rowne" << endl;
    }
}
