/*
 * main.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: student
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
	string wiersz="";
	int counter=0;
	cout << "podaj tekst" << endl;
	getline(cin, wiersz);

	for (size_t i = 0; i < wiersz.length(); ++i) {
		if((wiersz[i]-'0'<10)&&(wiersz[i]-'0'>0)) counter++;
	}
	cout << counter<<endl;
}

