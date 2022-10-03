#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

double esp = 0.00001;

int main(){
    int n = 2;
    vector<vector<double>> ar(n, vector<double>(n));
    double give_input[n*n] = {esp,2,1,-1};
    double input[n] = {4,1};  
    int kk = 0; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ar[i][j] = give_input[kk];
            kk++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ar[i][j] <<" ";
        }
        cout<<"\n";
    }
    for(int k=0; k<n-1; k++){
       // uncomment for partial
        // int max_index = k;
        // for(int i = k+1; i<n; i++){
        //     if(ar[i][k] > ar[max_index][k] ){
        //         max_index = k;
        //     }
        // }
        // swap(ar[k],ar[max_index]);
        // swap(input[k], input[max_index]);
        for(int i=k+1; i<n; i++){
            double factor = ar[i][k] / ar[k][k];
            ar[i][k] = (double)0;
            for(int j=k+1; j<n; j++){
                ar[i][j] -= factor * ar[k][j];
            }
            input[i] -= factor*input[k];
        }
    }

    vector<double> output(n,0);
    output[n-1] = input[n-1] / ar[n-1][n-1];
    for(int i=n-2; i>=0; i--){
        double add = input[i];
        for(int j=i+1; j<n; j++){
            add -= ar[i][j] * output[j];
        }
        output[i] = add / ar[i][i];
    }
    for(int i=0; i<n; i++){
        cout<<output[i]<<" ";
    }

}