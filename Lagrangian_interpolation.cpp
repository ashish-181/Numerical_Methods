//lagrangian interpolation
#include<bits/stdc++.h>
using namespace std;
#define float double

int main(){
    int n = 14; // size of the data
    vector<pair<float,float>> temp_cp_data;
    float temp_ar[n] = {250,300,350,400,450,500,550,600,650,700,750,800,900,1000};
    float cp_ar[n] = {1.003,1.005,1.008,1.013,1.02,1.029,1.040,1.051,1.063,1.075,1.087,1.099,1.121,1.142};
    for(int i=0; i<n; i++){
        temp_cp_data.push_back({temp_ar[i], cp_ar[i]});   
    }
    //sort(temp_cp_data.begin(), temp_cp_data.end());

    float x = 200 ,y = 0.0;

    int order = 13; // give the order

    vector<pair<float,int>> find_points;
    
    for(int i=0; i<n; i++){
        find_points.push_back( {abs(temp_cp_data[i].first - x) ,i});
    }
    sort(find_points.begin(), find_points.end());
    // got the required points
    // for(auto it : find_points){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // now answer

    for(int i=0 ; i<order+1; i++){
        float numerator = 1;
        float denominator = 1;
        for(int j=0; j<order+1; j++){
            if(i != j)
                numerator *= ( x- temp_cp_data[find_points[j].second].first );
        }
        for(int j=0; j<order+1; j++){
            if( i!= j)
                denominator *= ( temp_cp_data[find_points[i].second].first - temp_cp_data[find_points[j].second].first );
        }
       // cout<<numerator<<" "<<denominator<<"\n";
         y += (numerator * temp_cp_data[find_points[i].second].second )/denominator;
    }

    cout<<fixed<<setprecision(9)<< y;

}
