#include<iostream>
#include<cmath>
using namespace std;
double esp = 0.0001;

double check(double x){
    // write the equation
    return x*x*x - x*x +2;
}

int main(){
    double x_m = -2, x_p = 3;

   double x_r;
    while( true ){
        double x_r = (x_m + x_p)/2;
        
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
