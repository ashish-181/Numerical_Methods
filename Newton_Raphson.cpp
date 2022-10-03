#include<iostream>
#include<cmath>
using namespace std;
double esp = 0.0001;

double fun(double x){
    // write the equation
    // return  pow(x*x*x + 2, 0.5);
    //return (x*x + (double)2 ) /(double)3;
    return x*x- 3*x  +2;
}
double fun_dash(double x){
    return 2*x - 3;
}
int main(){
    double guess_value = 1.5;
    if(fun_dash(guess_value) == 0){
        cout<<"Not Possoble";
        return 0;
    }
    double first_iteration = guess_value - fun(guess_value) / fun_dash(guess_value);

    while( true){
        if(fun_dash(first_iteration) == 0){
            cout<<"Not Possoble";
            return 0;
        }
        double next_iteration = first_iteration -  fun(first_iteration) / fun_dash(first_iteration);
        if( abs( next_iteration - first_iteration ) <= esp){
            cout<<" root = "<< next_iteration;
            break;
        }
        first_iteration = next_iteration;
    }

}
 