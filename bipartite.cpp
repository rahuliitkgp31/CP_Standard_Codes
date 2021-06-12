#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph {
public:
    ll n;
    vector<ll>* adjList;
    vector<ll> vis;
    Graph(ll n) {
        this->n = n;
        adjList = new vector<ll>[n];
        vis.resize(n);
    }
    void addEdge(ll a, ll b) {
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    bool dfs(ll node, ll par, ll color) {
        vis[node] = color;
        for (ll i = 0; i < adjList[node].size(); i++) {
            if (vis[adjList[node][i]] == 0) {
                bool isBipartite = dfs(adjList[node][i], node, 3 - color);
                if (!isBipartite) return false;
            }
            else {
                if (adjList[node][i] != par && vis[adjList[node][i]] == color) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    if (g.dfs(0, -1, 1)) {
        cout << "Graph is Bipartite" << endl;
    }
    else {
        cout << "No graph is not Bipartite" << endl;
    }
    return 0;
}
