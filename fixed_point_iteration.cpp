#include<iostream>
#include<cmath>
using namespace std;
double esp = 0.0001;

double fun(double x){
    // write the equation
    // in this we find g_dash(x) < 1
    // return  pow(x*x*x + 2, 0.5);
    return (x*x + 2 )/3;
}

int main(){
    double guess_value = 0.0;
    double first_iteration = fun(guess_value);

    while( true){
        double next_iteration = fun(first_iteration);
        if( abs( next_iteration - first_iteration ) <= esp){
            cout<<" root = "<< next_iteration;
            break;
        }
        first_iteration = next_iteration;
    }

}
