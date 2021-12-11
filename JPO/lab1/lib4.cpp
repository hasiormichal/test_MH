
#include <cmath>

void  FUNKCJA (double* x , int wielkosc, double *  srednia , double * odchylenie){

double sre=0,odh=0;

for (int i=0; i<wielkosc ;i++ ){
    sre = sre + *(x+i);
}
sre = sre / wielkosc;

for(int i=0; i<wielkosc ;i++ ){
    odh = odh + pow(*(x+i) - sre,2);
}
odh = sqrt(odh/wielkosc);

*srednia = sre;
*odchylenie = odh; 

return;
}