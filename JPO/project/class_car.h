
#include <string.h> 
#include <strings.h> 
using namespace std;

class car{
    public:
    void print();
    car(string,string , string , string, string);
    string get_cena();
    string get_id();
    string class_to_string();
};
class rent_car{
    public:
    rent_car( string,string , string , string, string, string ,string);
    void print();
    void oblicz_cene(int);
    void set_stop_time(string);
    string class_to_string();
    int wyporzycz(string , string);
};