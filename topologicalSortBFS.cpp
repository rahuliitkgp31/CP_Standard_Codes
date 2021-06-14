#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph {
public:
    ll n;
    vector<ll>* adjList;
    vector<ll> inDegree;
    vector<ll> vis;
    vector<ll> topoOrder;
    Graph(ll n) {
        this->n = n;
        adjList = new vector<ll>[n];
        inDegree.resize(n);
        vis.resize(n);
    }
    void addEdge(ll a, ll b) {
        adjList[a].push_back(b);
        inDegree[b]++;
    }
    void bfs() {
        queue<ll> q;
        for (ll i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (!q.empty()) {
            ll node = q.front();
            topoOrder.push_back(node);
            q.pop();
            for (ll i = 0; i < adjList[node].size(); i++) {
                ll nei = adjList[node][i];
                if (!vis[nei]) {
                    inDegree[nei]--;
                    if (inDegree[nei] == 0) {
                        q.push(nei);
                        vis[nei] = 1;
                    }
                }
            }
        }
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
    g.bfs();
    for (ll i = 0; i < n; i++) {
        cout << g.topoOrder[i] << " ";
    }
    cout << endl;
    return 0;
}
