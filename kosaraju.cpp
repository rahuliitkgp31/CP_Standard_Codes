#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(vector<ll>* g, ll node, vector<ll>& vis, stack<ll>& s) {
    vis[node] = 1;
    for (ll i = 0; i < g[node].size(); i++) {
        if (!vis[g[node][i]]) {
            dfs(g, g[node][i], vis, s);
        }
    }
    s.push(node);
}

void dfs1(vector<ll>* g, ll node, vector<ll>& vis) {
    vis[node] = 1;
    cout << node << " ";
    for (ll i = 0; i < g[node].size(); i++) {
        if (!vis[g[node][i]]) {
            dfs1(g, g[node][i], vis);
        }
    }
}

void kosaRaju(vector<ll>* g, vector<ll>* rg, ll n) {
    vector<ll> vis(n);
    stack<ll> s;
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(g, i, vis, s);
        }
    }
    for (ll i = 0; i < n; i++) {
        vis[i] = 0;
    }
    while (!s.empty()) {
        ll currEle = s.top();
        s.pop();
        if (vis[currEle]) continue;
        else {
            dfs1(rg, currEle, vis);
            cout << endl;
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll>* g = new vector<ll>[n];
    vector<ll>* rg = new vector<ll>[n];
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    kosaRaju(g, rg, n);
    return 0;
}

//7 8
//0 1
//1 2
//2 0
//1 3
//3 4
//3 5
//5 6
//6 3
