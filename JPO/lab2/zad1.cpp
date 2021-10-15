#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;

class point2d {
        public:
        double x,y;
    
        void set_x(double _x){
            x = _x;
        } 
        void set_y(double _y){
            y = _y;
        }
        double get_y() const{
            return y;
        }
        double get_x() const{
            return x;
        }

        //construktor
        
        point2d(double argx =0, double argy=0){
            x = argx;
            y = argy;
        }
};

class circle {
    public:
        double r,x,y;

        circle( double argr=1,double argx=0, double argy=0){
            r=argr;
            x=argx;
            y=argy;
        }

        bool is_inside(const point2d& p){
            double a = sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
            if(a <=1) return true;
            else return false;
        }


};


int main(){

double x1 = 1.5;
double y1 = 1.5;
double ni=0,n=0;
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
uniform_real_distribution<double> distribution{-1.0,1.0};
distribution(gen);

point2d c(x1,y1);
circle kolo(1 ,0,0);

for (uint64_t i=0; i<1000000 ;i++){
    c.set_x(distribution(gen));
    c.set_y(distribution(gen));
    if(kolo.is_inside(c)){
        ni++;
        n++;
    }
    else{
       n++; 
    }
}
//cout << ni << endl;
//cout << n << endl;
cout << "pi ~ " << ((ni*4)/n) << endl;
/*
c.set_y(x1);
double test =  c.get_y();
double test2 = c.get_x();
cout << test << endl;
cout << test2 << endl; 
*/


exit(0);
}