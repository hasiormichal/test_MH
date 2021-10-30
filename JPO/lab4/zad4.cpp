#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;


void print(vector<vector<double>> &macierz){
    for(int i=0 ; i < macierz.size() ; i++){
        cout << "|";
        for(int j = 0 ; j <  macierz[0].size() ; j++ ){

            cout << macierz[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

vector<vector<double>> tran(vector<vector<double>> &macierz2){
    vector<vector<double>> wynik2{macierz2};
    for(int i=0 ; i < macierz2.size() ; i++){
        // << "|";
        for(int j = 0 ; j <  macierz2[0].size() ; j++ ){

            wynik2[j][i] = macierz2[i][j];
        }
        //cout << "|" << endl;
    }
    return wynik2;
}




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

vector<vector<double>> sum(vector<vector<double>> &wektor1 , vector<vector<double>> &wektor2 ){
    vector<vector<double>> wynik{wektor1}; 

    if(wektor2.size() != wektor1.size()){
        cout << "wymiary wektorów są różne" << endl;
        return wynik;
    }


    for(int i=0; i < wektor2.size() ; i++ ){
        wynik[i] = sum(wektor1[i] , wektor2[i]);
    }
    return wynik;
}


int main(int argc, char **argv) {

    vector<vector<double>> macierz1{} ,macierz2{},wynik{};

    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> distribution{-10.0,10.0};
    //distribution(gen);
    
    int dlugosc =5;


    vector<double> tmp{};

    for(int i=0 ; i < dlugosc ; i++){
        tmp.push_back(distribution(gen));

    }


    for(int i=0 ; i < dlugosc ; i++){
        macierz1.push_back(tmp); 
        for(int j=0 ; j < dlugosc ; j++){
            tmp[j] = distribution(gen);
        }
        
        macierz2.push_back(tmp);

        for(int j=0 ; j < dlugosc ; j++){
            tmp[j] = distribution(gen);
        }
    }  

    //suma
    wynik = sum(macierz1 , macierz2);

    print(macierz1);
    cout << endl;
    print(macierz2);
    cout << endl;
    print(wynik);
    cout << endl;

    wynik = tran(wynik);
    print(wynik);
    cout <<endl;

}