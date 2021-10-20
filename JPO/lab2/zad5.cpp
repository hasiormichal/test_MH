//============================================================================
// Name        : zad5.cpp

//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SmartArray {
public:
	//konstruktor parametryczny i kopiujacy
	SmartArray(int arg_size) {
		size = arg_size;
		tablica = new double(size);
		srand(time(0));
		max = 0;
		for (int i = 0; i < arg_size; ++i) {
			*(tablica + i) = rand() % 1000;
			if (max < *(tablica + i))
				max = *(tablica + i);
		}
		cout << "wywołano konstruktor parametryczny" << endl;
	}
	SmartArray(SmartArray &source_arr) {
		size = source_arr.size;
		max = source_arr.max;
		tablica = new double(size);
		for (int i = 0; i < size; ++i) {
			*(tablica + i) = *(source_arr.tablica + i);
		}
		cout << "wywołano konstruktor kopiujacy" << endl;
	}
	~SmartArray() {
		delete tablica;
		cout << "wywołano konstruktor" << endl;
	}
	//metody
	double at(int index) {
		if (index > size) {
			cout << "podano indeks wiekszy niz rozmiar tablicy" << endl;
			return -1;
		} else
			return *(tablica + index);
	}
	int set_at(int index, double value) {
		if (index > size) {
			cout << "podano indeks wiekszy niz rozmiar tablicy" << endl;
			return -1;
		}
		*(tablica + index) = value;
		return 0;
	}
private:
	double *tablica;
	int size;
	double max;
};

int main() {
	int size = 16;
	cout << "stworzono tablice o liczbie elementow " << size << endl;
//	cin >> size;
	SmartArray myarr(size);
	myarr.print();
	cout << myarr.at(size / 2) << endl;
	return 0;
}
