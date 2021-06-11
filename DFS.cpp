#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph{
public:
    ll n;
    vector<ll>* adjList;
    vector<ll> vis;
    Graph(ll n){
        this->n = n;
        adjList = new vector<ll>[n];
        vis.reserve(n);
    }
    void addEdge(ll a, ll b){
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    void dfs(ll node){
        vis[node]=1;
        cout<<node<<" ";
        for(ll i=0; i<adjList[node].size(); i++){
            if(!vis[adjList[node][i]]){
                dfs(adjList[node][i]);
            }
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(2, 1);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(0);
    return 0;
}
