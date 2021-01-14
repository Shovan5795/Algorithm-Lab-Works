#include <bits/stdc++.h>

using namespace std;
#define inf 9999

int dis[100][100], seq[100][100];

void floydwarshell(int dis[][100], int seq[][100], int nodes){
    int Dk[100][100], Sk[100][100];

    for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
            if(i==j){
                Dk[i][j] = inf;
                Sk[i][j] = inf;
            }
            else{
                Dk[i][j] = 0;
                Sk[i][j] = 0;
            }
        }
    }

    for(int k=1; k<=nodes; k++){
        for(int rc=1; rc<=nodes; rc++){
            Dk[k][rc] = dis[k][rc];
            Sk[k][rc] = seq[k][rc];

            Dk[rc][k] = dis[rc][k];
            Sk[rc][k] = seq[rc][k];

        }

        for(int i=1; i<=nodes; i++){
            if(i == k) continue;
            for(int j=1; j<=nodes; j++){
                if(j==k) continue;
                if(i==j) continue;

                if(dis[i][j]> dis[i][k] + dis[k][j]){
                    Dk[i][j] = dis[i][k] + dis[k][j];
                    Sk[i][j] = k;
                }
                else{
                    Dk[i][j] = dis[i][j];
                    Sk[i][j] = seq[i][j];
                }
            }
        }
        for(int i=1; i<=nodes; i++){
            for(int j=1; j<=nodes; j++){
                dis[i][j] = Dk[i][j];
                seq[i][j] = Sk[i][j];
            }
        }

        cout<<"Distance table after "<<k<<" th iteration: "<<endl;
        for(int i=1; i<=nodes; i++){
            for(int j=1; j<=nodes; j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"Sequence table after "<<k<<" th iteration: "<<endl;
        for(int i=1; i<=nodes; i++){
            for(int j=1; j<=nodes; j++){
                cout<<seq[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;


    }

}

int main(){

    freopen("input.txt", "r", stdin);

    int nodes, edges, n1, n2, w;
    cin>>nodes>>edges;

    for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
                dis[i][j] = inf;
                seq[i][j] = inf;
        }
    }

    for(int i=1; i<=edges; i++){
        cin>>n1>>n2>>w;
        dis[n1][n2]=w;
    }

    for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
            if(i !=j)seq[i][j] = j;
        }
    }

        cout<<"Distance table after  0 th iteration: "<<endl;
        for(int i=1; i<=nodes; i++){
            for(int j=1; j<=nodes; j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"Sequence table after 0 th iteration: "<<endl;
        for(int i=1; i<=nodes; i++){
            for(int j=1; j<=nodes; j++){
                cout<<seq[i][j]<<" ";
            }
            cout<<endl;
        }

    cout<<endl;
    floydwarshell(dis, seq, nodes);


}
