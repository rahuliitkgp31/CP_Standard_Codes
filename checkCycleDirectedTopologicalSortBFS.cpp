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
    bool isCycle() {
        queue<ll> q;
        for (ll i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
        ll cnt = n;
        while (!q.empty()) {
            cnt--;
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
        return cnt != 0;
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
    if (g.isCycle()) {
        cout << "Cycle is present" << endl;
    }
    else {
        cout << "No cycle is present" << endl;
    }
    return 0;
}
