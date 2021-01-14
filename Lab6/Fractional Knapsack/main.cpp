#include <bits/stdc++.h>

using namespace std;



void frac_knapsack(int n, float weight[], float profit[], float capacity){
    float x[100] = {0.0}, tp = 0.0;

    for(int i=0; i<n; i++){
        if(weight[i]> capacity)break;
        else{
            x[i] = 1.0;
            tp = tp + profit[i];
            capacity = capacity - weight[i];
        }
    }
    for(int i=0; i<n; i++){
        if(x[i] != 1.0 && capacity >= 0){
            x[i] = capacity/ weight[i];
            tp = tp + x[i]*profit[i];
        }
    }

    for(int i=0; i<n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl<<tp;



}

int main()
{

    freopen("input1.txt", "r", stdin);
    int n;
    float weight[100], profit[100], capacity, r[100], temp;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>profit[i];
    }
    cin>>capacity;
    for(int i=0; i<n; i++){
        r[i] = profit[i]/weight[i];
        cout<<r[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(r[i] < r[j]){
                temp = r[j];
                r[j] = r[i];
                r[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<r[i]<<"---->"<<weight[i]<<"---->"<<profit[i]<<endl;
    }

    frac_knapsack(n, weight, profit, capacity);


    return 0;
}
