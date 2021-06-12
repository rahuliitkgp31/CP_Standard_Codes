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
    bool dfs(ll node, ll par) {
        vis[node] = 1;
        for (ll i = 0; i < adjList[node].size(); i++) {
            ll ch = adjList[node][i];
            if (!vis[ch]) {
                bool isCyclePresent = dfs(ch, node);
                if (isCyclePresent) {
                    return true;
                }
            }
            else {
                if (par != ch) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(0, 4);

    if (g.dfs(0, -1)) {
        cout << "Contains cycle" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
