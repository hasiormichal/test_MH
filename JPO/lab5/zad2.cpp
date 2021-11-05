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

    map <char,int> nazwa;
    string wejscie;

    cout << "podaj wyraz" << endl;
    getline(cin,wejscie);

    for(const char znak:wejscie){
        if(nazwa.find(znak) == nazwa.end()){
            nazwa[znak] = 1;
        }else{
            nazwa[znak]++;
        }
    }

    for(auto element:nazwa){

        cout << element.first << " - "<<element.second << endl;
    }
}