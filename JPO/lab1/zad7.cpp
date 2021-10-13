/* 
 * Składnia języka C/C++ udostępnia przydatną w niektórych sytuacjach instrukcję wyboru switch-case.
 *Używając instrukcji switch-case, napisz niewielki kalkulator, który pobiera na wejściu jeden z operatorów
 *arytmetycznych oraz dwa argumenty, po czym wyświetla wynik obliczeń otrzymany na podstawie tych
 *danych. Program powinien zakończyć swoje działanie po wprowadzeniu litery q zamiast operatora
 *arytmetycznego.
 */
#include <iostream>
using namespace std;
int main(void){
	int a,b;
	char op;
	bool end=1;
	while(end){
	cout << "podaj wyrazenie w postaci 'liczba' 'operator' 'liczba'\n";
	cout << "aby zakonczyc w pole operator 'q'" << endl;
	cin >> a >> op >> b;
	switch(op){
		case '+' :
			cout << a<< "+"<< b<< "="<<a+b<<endl;
			break;
		case '-' :
			cout << a<< "-"<< b<< "="<<a-b<<endl;
			break;
		case '*' :
			cout << a<< "*"<< b<< "="<<a*b<<endl;
			break;
		case '/' :
			cout << a<< "/"<< b<< "="<<a/b<<endl;
			break;	
		case 'q' :
			end=0;
			break;
	}
}
	exit(0);
}
