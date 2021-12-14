
#include <string.h> 
#include <strings.h> 
using namespace std;

class car{
    public:
    void print();
    car(string , string , string, string);
    string get_cena();
    string to_string();
};
class rent_car{
    public:
    rent_car( string , string , string, string, string ,string);
    void print();
    void oblicz_cene(int);
    string to_string();
};