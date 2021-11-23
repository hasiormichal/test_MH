#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int silnia(int x){
    if(x > 0){
        return x*silnia(x-1);
    }else if(x ==0 )
        return 1;
    else{
        cout << "podano ujemną wartość" << endl;
        return 0;
    }   
}


int main(){
cout << "podaj liczbe naturalną" << endl;
int liczba{};
cin >> liczba;
cout << silnia(liczba) << endl;
}