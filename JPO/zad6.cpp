/*
 * Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę całkowitą n (n > 2) i wypisuje na
 * standardowym wyjściu największą liczbę k taką, że k dzieli n przy założeniu, że k < n. Algorytm
 * wyszukiwania liczby k spełniającej powyższe warunki umieść w oddzielnej funkcji
 */
 
 #include <iostream>
 using namespace std;
 int main(void){
	 int n=0;
	 do{ //do skótku
	 cout << "podaj liczbe n>2" << endl;
	 cin >> n;
	}while(n<2);	
	cout << n << endl;
	exit(0);
 }
