#include<iostream>
#include<cmath>
using namespace std;
double esp = 0.0001;

double check(double x){
    // write the equation
    return x*x*x - x*x +2;
}

int main(){
    double x_m = -200, x_p = 300;

   double x_r;
    while( true ){
        double get_xp = check(x_p);
        double get_xm = check(x_m);
        double x_r = x_p - get_xp * ((x_p- x_m) / (get_xp - get_xm));        
        double get_value = check(x_r);
        if( abs(get_value) < esp){
            cout<<" root = "<<x_r<<endl;
            break;
        }
        if(get_value < 0)
            x_m = x_r;
        else  
            x_p = x_r;
    }
}
