#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void dec_to_bin(int liczba)
{
	int i=63;
    int spacja =0 ;
	bool ok=false;
	while(i--)
	{
		//warunek, który pozwoli ominąć początkowe zera
		if(liczba>>i&1&!ok) 
			ok=true;
		if(ok)
			cout<<((liczba>>i)&1);
        spacja ++;
        if(spacja == 8){
            cout << " ";
           spacja = 0;    
        }
	}
}

int main()
{
	int liczba;
	cout<<"Podaj liczbę: ";
	cin>>liczba;

	cout<<liczba<<" po zamianie na postać binarną: ";
	dec_to_bin(liczba);
	cout<<endl;

	return 0;
}