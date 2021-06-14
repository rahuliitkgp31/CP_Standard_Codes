#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph {
public:
    ll n;
    vector<ll>* adjList;
    vector<ll> vis;
    vector<ll> topoOrder;
    Graph(ll n) {
        this->n = n;
        adjList = new vector<ll>[n];
        vis.resize(n);
    }
    void addEdge(ll a, ll b) {
        adjList[a].push_back(b);
    }
    void dfs(ll node) {
        vis[node] = 1;
        for (ll i = 0; i < adjList[node].size(); i++) {
            if (!vis[adjList[node][i]]) {
                dfs(adjList[node][i]);
            }
        }
        topoOrder.push_back(node);
    }
    void topoloicalSort() {
        for (ll i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        reverse(topoOrder.begin(), topoOrder.end());
        for (ll i = 0; i < n; i++) {
            cout << topoOrder[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.topoloicalSort();
    return 0;
}
