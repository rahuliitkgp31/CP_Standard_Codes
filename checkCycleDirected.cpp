#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph {
public:
    ll n;
    vector<ll>* adjList;
    vector<ll> stk;
    vector<ll> vis;
    Graph(ll n) {
        this->n = n;
        adjList = new vector<ll>[n];
        stk.resize(n);
        vis.resize(n);
    }
    void addEdge(ll a, ll b) {
        adjList[a].push_back(b);
    }
    bool isCycle(ll node) {
        stk[node] = 1;
        vis[node] = 1;
        for (ll i = 0; i < adjList[node].size(); i++) {
            ll nei = adjList[node][i];
            if (!vis[nei]) {
                bool subProb = isCycle(nei);
                if (subProb) {
                    return true;
                }
            }
            else {
                if (stk[nei]) {
                    return true;
                }
            }
        }
        stk[node] = 0;
        return false;
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
    if (g.isCycle(0)) {
        cout << "Cycle is present" << endl;
    }
    else {
        cout << "No cycle is present" << endl;
    }
    return 0;
}
