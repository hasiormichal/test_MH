#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

//#include "class_car.cpp"
#include "save_data.h"
#include "global.h"

void save_data(){

    ofstream output_file;
    output_file.open("plik.txt");
	if(output_file.good()){
        for(auto it=samochody.begin(); it !=samochody.end();  it++){

            if(auto itt=samochody.end() == it+1 ){
                output_file << (*it).class_to_string();
                break;
            }
            output_file << (*it).class_to_string()<< endl;

        }
        output_file.close();
    }
}