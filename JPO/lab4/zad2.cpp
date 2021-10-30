#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;


vector<double> sum(vector<double> &wektor1 , vector<double> &wektor2 ){
    vector<double> wynik{wektor1}; 

    if(wektor2.size() != wektor1.size()){
        cout << "wymiary wektorów są różne" << endl;
        return wynik;
    }


    for(int i=0; i < wektor2.size() ; i++ ){
        wynik[i] = wektor1[i] + wektor2[i];
    }
    return wynik;
}

int main(int argc, char **argv) {
    vector <double> v1{} , v2{} ;

    //dlugosc wektrorów
    int dlugosc = 5;

    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> distribution{-10.0,10.0};
    //distribution(gen);

    for(int i=0 ; i < dlugosc ; i++){
        v1.push_back(distribution(gen)); 
        v2.push_back(distribution(gen));
    }    

    vector<double> suma = sum(v1,v2);

    for (int i=0 ; i < suma.size() ; i++){
        cout << v1[i] << "  +  " << v2[i] << "  =  " << suma[i] << endl;

    }

    


}