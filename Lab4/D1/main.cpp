#include <bits/stdc++.h>

using namespace std;

#define INFINITY 99;
int node, edge, source;
int adj[100][100];

void dijkstra(int source){
    int distance[100], previous[100];
    int visited[100]={0}, Count, mindistance, nextnode, i, j;
    for(i = 0;i < node; i++){
		previous[i]= source;
		distance[i] = adj[source][i];
	}
	distance[source] = 0;
	visited[source] = 1;
	Count = 1;
	while(Count < node - 1){
		mindistance = INFINITY;
		for(i = 0;i< node; i++){
			if(distance[i] < mindistance && visited[i]==0){
				mindistance=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode] = 1;
		for(i = 0;i < node; i++){
			if(visited[i]==0){
				if(mindistance + adj[nextnode][i] < distance[i]){
					distance[i] = mindistance + adj[nextnode][i];
					previous[i]=nextnode;
				}
			}
		}
		Count++;
	}
	for(i=0;i < node; i++){
		if(i!=source){
			cout<<endl<<"Distance of node: "<<i<<" = "<<distance[i];
			cout<<endl<<"Path = "<<i;
			j=i;
			do{
			  	j=previous[j];
				cout<<" <-- "<< j;
			}
			while(j!=source);
		}
	}

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>> node;
    cin>> edge;
    int n1, n2, w;

    for(int i = 0; i< edge; i++){
        cin>>n1>>n2>>w;
        adj[n1][n2] = w;
    }

    for(int i = 0; i< node; i++){
        for(int j = 0; j<node; j++){
            if(adj[i][j] == 0){
                adj[i][j] = INFINITY;
            }
            //cout<<adj[i][j]<<" ";
        }
        //cout<<endl;
    }

    cin>>source;
    dijkstra(source);

    return 0;
}
