#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll bellmanFord(vector<vector<ll> >& edgeList, ll src, ll des, ll n) {
    vector<ll> dis(n, INT_MAX);
    dis[src] = 0;
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < edgeList.size(); j++) {
            ll a = edgeList[j][0];
            ll b = edgeList[j][1];
            ll wt = edgeList[j][2];
            if (dis[a] != INT_MAX && dis[b] > dis[a] + wt) {
                dis[b] = dis[a] + wt;
            }
        }
    }
    return dis[des];
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll> > edgeList;
        for (ll i = 0; i < m; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            --a, --b;
            edgeList.push_back({a, b, c});
        }
        ll src, des;
        cin >> src >> des;
        --src, --des;
        cout << bellmanFord(edgeList, src, des, n) << endl;
    }
    return 0;
}