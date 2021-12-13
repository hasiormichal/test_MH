
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>


#include "class_car.h"
#include "read_from_file.h"
#include "create_class.h"

using namespace std;

int main(){
    vector <string> odczytany_plik;
    odczytany_plik = read_from_file("plik.txt");


    //cout << odczytany_plik[0] << endl;
    //cout << odczytany_plik[1] << endl;
    create_class(odczytany_plik);

}