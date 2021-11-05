#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    map <string,string> nazwa;
    string wejscie;
    size_t linia = 0;
    string exit = "end";
    cout << "podawaj wyrazy" << endl;
    while(1){
        linia ++;
        getline(cin,wejscie);
        if(wejscie == exit)
            break;
        if(nazwa.find(wejscie) == nazwa.end()){
            nazwa[wejscie] = to_string(linia);
        }else{
            nazwa[wejscie] = nazwa[wejscie] + " "+ to_string(linia);
        }    
    }
    for(auto element:nazwa)
        cout << element.first << " - "<<element.second << endl;
}