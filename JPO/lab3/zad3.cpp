/*
 * main.c
 *
 *  Created on: Oct 22, 2021
 *      Author: student
 */
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char **argv) {
	string wiersz {
			"Congratulations Mrs. <name>, you and Mr. <name> are lucky recipents of a trip for two to XXXXXXXXX. Your trip to XXX is already scheduled " };
	size_t name_poz = 1;
	cout << "before: " << wiersz << endl;
	//find name
	do {
		name_poz = wiersz.find("<name>");
		if (name_poz != string::npos)
			wiersz.replace(name_poz, 6, "Smith");
	} while (name_poz != string::npos);

	//find XXXX
	do {
		name_poz = wiersz.find("X");
		//delete next X
		int i = 1;
		while (wiersz[name_poz + i] == 'X') {
			i++;
		}
		if (name_poz != string::npos)
			wiersz.replace(name_poz, i, "Siberia");

	} while (name_poz != string::npos);
	//make lucky unlucky
	name_poz = wiersz.find("lucky");
	wiersz.insert(name_poz,"un");

	// dodawanie "in Deember"

	wiersz.append("in December");

	cout << "after: "<<wiersz << endl;
	return 0;
}

