#include <iostream>
#include <cmath>

using namespace std;

class TQuadEq{
	private:
		double a,b,c;
	public:
		//settery
		void set_a(double arg_a){
            a = arg_a;
        } 
        void set_b(double arg_b){
            b = arg_b;
        } 
        void set_c(double arg_c){
            c = arg_c;
        } 
        
        //gettery
        double get_a(void) const{
			return a;
			}
        double get_b(void) const{
			return b;
			}
        double get_c(void) const{
			return c;
		}

        //konstruktor
		TQuadEq(double arg_a=1,double arg_b=0,double arg_c=0){
			a=arg_a;
			b=arg_b;
			c=arg_c;
		}
		//metody
		double ComputeDelta(void) const{
			return ((b*b)-4*a*c);
		}
		int GetNumRoots(const double delta) const{
			if(delta>0) return 2;
			else if(delta==0) return 1;
			else return 0;
		}
		void GetRoots(double& root1, double& root2)const{
			double _delta = ComputeDelta();
			root1=((-1.0)*b - sqrt(_delta))/(2.0*a);
			root2=((-1.0)*b + sqrt(_delta))/(2.0*a);
		}
};
int main(void){
	double a,b,c,delta,x1,x2;
     
    cout << "Podaj wspolczynnik a:" << endl;
    cin >> a;
    cout << "Podaj wspolczynnik b:" << endl;
    cin >> b;
    cout << "Podaj wspolczynnik c:" << endl;
    cin >> c;
    TQuadEq wiel(a,b,c);
//    wiel.set_a(a);
//    wiel.set_b(b);
//    wiel.set_c(c);
    delta=wiel.ComputeDelta();
    cout << "liczba pierwiastkow to " << wiel.GetNumRoots(delta) << endl;
    if(wiel.GetNumRoots(delta)==2){
		wiel.GetRoots(x1,x2);
		cout << "x1 = " << x1 << "\nx2 = " << x2 << endl;
	}
	else if(wiel.GetNumRoots(delta)==1){
		wiel.GetRoots(x1,x2);
		cout << "x = " << x1 << endl;
	}
}
