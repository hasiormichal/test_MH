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

int main(int argc, char **argv) {
	ifstream input_file;
	ofstream output_file;
	string wiersz { }, owiersz { };

	input_file.open(
			"./plik_tekstowy.txt");
	if (input_file.good()) {
		getline(input_file, wiersz);
		input_file.close();
		owiersz = wiersz;
		cout << wiersz << endl; //TODO odwracanie w funkcji
		for (int i = wiersz.length()-1; i >= 0; --i) {
			owiersz[wiersz.length() - i-1] = wiersz[i];
		}
		output_file.open(
				"./plik_wyjsciowy.txt");
		output_file << owiersz << endl;
		output_file.close();
	}
}

