#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {

vector <string> zakupy{""};

cout << zakupy[0] << endl;

zakupy.push_back("wino");
zakupy.push_back("buraki");
zakupy.push_back("banany");
zakupy.push_back("cukier");
zakupy.push_back("czekolada");
zakupy.push_back("marchew");

cout << zakupy[zakupy.size() - 1 ] << endl;
zakupy.erase(zakupy.end() - 1 );

//cout << zakupy[zakupy.size() - 1 ] << endl;

zakupy.insert(zakupy.begin() + 3, "kawa");

//pentla printująca 
for(int i=0; i<zakupy.size() ; i++){
    cout << zakupy[i] << " ";

}
cout << endl;

for(int i=0; i<zakupy.size() ; i++){
    if(zakupy[i] == "cukier"){
        zakupy[i] = "cukierki";
    }
}

//pentla printująca 
for(int i=0; i<zakupy.size() ; i++){
    cout << zakupy[i] << " ";

}
cout << endl;

for(int i=0; i<zakupy.size() ; i++){
    if(zakupy[i] == "czekolada"){
        zakupy.erase(zakupy.begin() + i);
    }
}

//pentla printująca 
for(int i=0; i<zakupy.size() ; i++){
    cout << zakupy[i] << " ";

}
cout << endl;

sort(zakupy.begin(),zakupy.end());

//pentla printująca 
for(int i=0; i<zakupy.size() ; i++){
    cout << zakupy[i] << " ";

}
cout << endl;

}