#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "read_from_file.h"
using namespace std;


vector <string> read_from_file(string path){
    ifstream input_file;
    input_file.open(path);
    vector <string> zawartosc;
    string buffor = {};

    if(input_file.good()){
        while (1) //czytaj do wektora cały plik
        {
            getline(input_file,buffor);
            zawartosc.push_back(buffor);
            if (input_file.eof())
                break;
        }
    }
    else{
        cout << "bład otwarcia pliku\n";
    }

    return zawartosc;

}