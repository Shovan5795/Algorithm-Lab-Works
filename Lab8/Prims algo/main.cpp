#include <bits/stdc++.h>

using namespace std;

#define INFINITY 99

int minKey(int key[], bool mstSet[],int nodes)
{
    int Min = INFINITY, min_index;

    for (int v = 0; v < nodes; v++)
        if (mstSet[v] == false && key[v] < Min)
            Min = key[v], min_index = v;

    return min_index;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int nodes, edges, P[100][100];

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
                P[i][j] = 0;
        }
    }
    cin>>nodes>>edges;
    int n1, n2, w;

    for(int i=0; i<edges; i++){
        cin>>n1>>n2>>w;
        P[n1][n2] = w;
        P[n2][n1] = w;
    }

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    int parent[nodes], key[nodes], total = 0;
    bool mstSet[nodes];

    for(int i = 0; i< nodes; i++){
        key[i] = INFINITY;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    int u;

    for(int i=0; i< nodes-1; i++){
        int u = minKey(key, mstSet, nodes);
        mstSet[u] = true;

        for(int v=0; v<nodes; v++){
            if(P[u][v] && mstSet[v] == false && P[u][v] < key[v]){
                parent[v] = u;
                key[v] = P[u][v];
            }
        }
    }

    for(int i = 1; i<nodes; i++){
        cout<<parent[i]<<" "<< i<<" "<<P[i][parent[i]]<<endl;
        total += P[i][parent[i]];
    }
    cout<<"Total cost:" <<total;

    return 0;
}
