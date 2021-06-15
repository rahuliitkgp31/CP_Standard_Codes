#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph {
public:
    vector<pair<ll, ll> >* adjList;
    ll n;
    Graph(ll n) {
        this->n = n;
        adjList = new vector<pair<ll, ll> >[n];
    }
    void addEdge(ll a, ll b, ll w) {
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }
    ll prims() {
        vector<ll> vis(n);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
        pq.push({0, 0});
        ll ans = 0;
        while (!pq.empty()) {
            ll node = pq.top().second;
            ll wei = pq.top().first;
            pq.pop();
            if (vis[node]) continue;
            vis[node] = 1;
            ans += wei;
            for (ll i = 0; i < adjList[node].size(); i++) {
                ll ch = adjList[node][i].first;
                ll edgeWei = adjList[node][i].second;
                if (!vis[ch]) {
                    pq.push({edgeWei, ch});
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
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g.addEdge(a, b, c);
    }
    cout << g.prims() << endl;
    return 0;
}