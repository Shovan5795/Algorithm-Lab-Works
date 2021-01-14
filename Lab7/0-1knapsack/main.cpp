#include <bits/stdc++.h>

using namespace std;


int main()
{
    freopen("input1.txt", "r", stdin);
    int n, i, w;
    int weight[100], profit[100], V[100][100], x[100] = {0};
    int capacity;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>weight[i]>>profit[i];
    }
    cin>>capacity;

    for(w = 0; w <= capacity; w++) {
            V[0][w] = 0;
    }
    for(i = 0; i <= n; i++) {
            V[i][0] = 0;
    }



    for(i=1; i<=n; i++){
        for(w=1; w<=capacity; w++){
            if(weight[i] <= w){
                V[i][w] = max(V[i-1][w], profit[i] + V[i-1][w - weight[i]]);
            }
            else{
                V[i][w] = V[i-1][w];
            }
        }
    }

    cout<<"Max Profit:"<<V[n][capacity]<<endl;

    for(i=0; i<=n; i++){
        for(w=0; w<=capacity; w++){
           cout<<V[i][w]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    i = n;
    w = capacity;

    while(i>0 && w>0){
        if(V[i][w] != V[i-1][w]){
            x[i] = 1;
            cout<<"Item: "<<i<<" has been taken"<<endl;
            w = w - weight[i];
            i = i - 1;
        }
        else{
            i = i - 1;
        }
    }


    return 0;
}
