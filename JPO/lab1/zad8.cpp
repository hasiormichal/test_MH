/*
 * zad8.cpp
 * 
 *
 * Napisz program wczytujący ze standardowego wejścia dwie dodatnie liczby całkowite n i m, i wypisujący w
 *kolejnych wierszach na standardowym wyjściu wszystkie dodatnie wielokrotności n mniejsze od m.
 */

#include <iostream>
using namespace std;

int main(void){
	uint n=0,m=0;
	cout << "podaj dwie liczby"<< endl;
	cin >> n >> m;
	if (n>m){
		cout << n << "jest wieksze od "<< m<< endl;
		return(1);
	}
	uint mul=0;
	cout<<"wielokrotnosci to :\n";
	do{
		mul+=n;
		cout << mul << "\n";
	}while(m-mul>n);
	
	exit(0);
}
