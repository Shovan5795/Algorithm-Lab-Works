#include <bits/stdc++.h>

using namespace std;
#define inf 9999

struct edge{
    int u;
    int v;
    int w;

};

struct graph{
    int V;
    int E;
    struct edge *edge;
};

void Bellmanford(graph* g, int source){
    int u, v, w, V, E;
    V = g->V;
    E = g->E;
    int d[V], p[V];

    for(int i=0; i<V; i++){
        d[V] = inf;
        p[V] = inf;
    }
    d[source] = 0;
    p[source] = NULL;

    for(int i=0; i<V-1; i++){
        for(int j=0; j<E; j++){
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;

            if(d[u] != inf && d[u] + w < d[v]){
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }

    for(int i=0; i<E; i++){
            u = g->edge[i].u;
            v = g->edge[i].v;
            w = g->edge[i].w;

            if(d[u] != inf && d[u] + w < d[v]){
                cout<<"Negative cycle detected. We cannot find shortest path.";
                return;
            }
    }

    cout<<"Shortest distance from source to all other nodes: "<<endl;
    for(int i=0; i<V; i++){
        cout<<d[i]<<" ";
    }
    cout<<endl<<"Predecessor of all nodes: "<<endl;;

    for(int i=0; i<V; i++){
        cout<<p[i]<<" ";
    }

}



int main(){

    freopen("input1.txt", "r", stdin);

    struct graph *g = (struct graph*)malloc(sizeof(struct graph));

    cin>>g->V>>g->E;
    g->edge = (struct edge*)malloc(g->E* sizeof(struct edge));

    int E = g->E;
    for(int i=0; i< E; i++){
        cin>> g->edge[i].u>>g->edge[i].v>>g->edge[i].w;
    }

    int source;
    cin>>source;
    Bellmanford(g, source);
}
