/*
 * main.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: student
 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string string_revers(const string nazwa){
	string owiersz = nazwa;
	for (int i = nazwa.length()-1; i >= 0; --i) {
		owiersz[nazwa.length() - i-1] = nazwa[i];
	}
	return owiersz;
}

int main(int argc, char **argv) {
	ifstream input_file;
	ofstream output_file;
	string wiersz { };

	input_file.open(
			"./plik_tekstowy.txt");
	if (input_file.good()) {
		getline(input_file, wiersz);
		input_file.close();
		cout << wiersz << endl; //testowe wyświetlanie 

		string owiersz = string_revers(wiersz); //zamiana kolejności 
		// wpisanie do pliku wyjsciowego
		cout << owiersz << endl;
		output_file.open(
				"./plik_wyjsciowy.txt");
		output_file << owiersz << endl;
		output_file.close();
	}
	else{
		cout << "bład otwaria pliku" << endl;
	}
}

