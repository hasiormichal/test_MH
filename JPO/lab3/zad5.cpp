#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class kalkulator{
	private:
		double a,kwota;
        string nazwa;
	public:
        //konstruktor
        kalkulator(double _a=0, string _nazwa="PUSTO",double _kwota=0){  
			a = _a;
			nazwa = _nazwa;
            kwota = _kwota;
		}

    double kup(){
        return kwota / a;
    }
    double sprzedaj(){
        return kwota*a - (0.05 * kwota * a);
    }
};

int main(int argc, char **argv) {
	ifstream input_file;
	string wiersz1{ },wiersz2{};
    double cena{} ,cena2{};

	input_file.open(
			"./waluty.txt");
	if (input_file.good()) {  //kontrola poprawnowci pliku z danymi
            while(!input_file.eof()){   //petla bedzie czytac po lini az do konca pliku
            input_file >> wiersz1 >> cena;

            if(!(wiersz1 == "Euro"  || wiersz1 == "USD")){
                cout << "plik zawiera blad. pole " << wiersz1 << " nie jest poprawne" << endl;
                return 1;
            }
            if(cena < 0){
                cout << "kurs " << wiersz1 << " nie może byc ujemny" << endl;
            }       
        }
    }
    else{
        cout << "nie mozna otworzyc pliku " << endl;
    }

    cout << "plik jest ok" << endl;
    //TODO :zastanowic czy lepiej jest szczytywac cały plik teraz, czy lepiej to zdrobic juz podczas sprawdzania pliku
    input_file.seekg( 0 );
    input_file >> wiersz1 >>cena;
    input_file >> wiersz2 >>cena2;

    while(1){

        cout << "podaj kwote do zamiany" << endl;
        double kwota{};
        cin >> kwota;

        cout << "wybierz walute " << wiersz1 <<" " << wiersz2 << endl;
        string decyzja{};
        cin >> decyzja;

        if(decyzja == wiersz1){
            kalkulator test(cena,wiersz1,kwota);
            cout << "sprzedarz "<<wiersz1 << ": otrzymasz " << test.sprzedaj() <<" zl "<< endl;
            cout << "mozesz kupic: " << test.kup() <<" "<<wiersz1 << endl;
        }
        else if(decyzja == wiersz1){
            kalkulator test(cena2,wiersz2,kwota);
            cout << "sprzedarz "<<wiersz2 << ": otrzymasz " << test.sprzedaj() <<" zl "<< endl;
            cout << "mozesz kupic: " << test.kup() <<" "<<wiersz2 << endl;
        }
        else{
            cout << "podales zla walute"<< endl;
        }
        
        cout << "czy chcesz ponownie cos przeliczyć  y/n "<<endl;
        char koniec = 'n';
        cin >> koniec;

        if(koniec == 'n')
            return 0;
    }
    return 0;
} 
