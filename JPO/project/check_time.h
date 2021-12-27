using namespace std;

const int number_of_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int counting_of_days[12] = {0,31,59,90,120,151,181,212,243,273,304,334};

int check_date(string,string);
int check_calendary(string);
int number_of_days_in_between(string, string);