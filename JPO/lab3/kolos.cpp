#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
    string tekst{};
    char x = 'a';

    getline(cin,tekst);
    int zf=0;
    for (int i =0; i< tekst.length() ; i++){
        if (tekst[i] == ' '){
            continue;
        }
        zf = 'z' - int(tekst[i]);
        if(zf <= 2){
            tekst[i] = 'a' +2-zf;
        }
        else{
            tekst[i] = char(int(tekst[i]) + 3);
        }    

    }
    cout << tekst << endl;


}