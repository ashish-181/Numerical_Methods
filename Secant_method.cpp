#include<iostream>
#include<cmath>
using namespace std;
double esp = 0.0001;

double fun(double x){
    // write the equation
    // return  pow(x*x*x + 2, 0.5);
    //return (x*x + (double)2 ) /(double)3;
    return x*x*x - 5*x +1;
}
double fun_dash(double x){
    return 3*x*x - 3;
}
int main(){
    double guess1 = 0; // for negative
    double guess2 = 1; // for positive
    
    double value1 = guess2 - ( fun(guess2) * ( guess2 - guess1 ) )  / ( fun(guess2) - fun(guess1) );

    while( true){
        double next_iteration =  value1 - ( fun(value1) * ( value1 - guess2 ) )  / ( fun(value1) - fun(guess2) );
        if( abs( next_iteration - value1) < esp){
            cout<<"root is = "<<next_iteration;
            break;
        }
        guess2 = value1;
        value1 = next_iteration;
    }

}
 