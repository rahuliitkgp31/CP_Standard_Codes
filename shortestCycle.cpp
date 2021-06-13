#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph {
public:
    ll n;
    vector<ll>* adjList;
    vector<ll> dis;
    Graph(ll n) {
        this->n = n;
        adjList = new vector<ll>[n];
        dis.resize(n);
    }
    void addEdge(ll a, ll b) {
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    ll bfs(ll src) {
        ll ans = n + 1;
        for (ll i = 0; i < n; i++) dis[i] = INT_MAX;
        dis[src] = 0;
        queue<ll> q;
        q.push(src);
        while (!q.empty()) {
            ll ele = q.front();
            q.pop();
            for (ll i = 0; i < adjList[ele].size(); i++) {
                ll nei = adjList[ele][i];
                if (dis[nei] == INT_MAX) {
                    dis[nei] = dis[ele] + 1;
                    q.push(nei);
                }
                else {
                    if (dis[nei] >= dis[ele]) {
                        ans = min(ans, dis[ele] + dis[nei] + 1);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g.addEdge(a, b);
    }
    ll minCycleLength = n + 1;
    for (ll i = 0; i < n; i++) {
        minCycleLength = min(minCycleLength, g.bfs(i));
    }
    if (minCycleLength == n + 1) {
        cout << "No cycle found";
    }
    else {
        cout << "Cycle of length " << minCycleLength << " found" << endl;
    }
    return 0;
}
