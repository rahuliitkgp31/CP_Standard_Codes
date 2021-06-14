#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Dsu {
public:
    vector<ll> par;
    vector<ll> rank;
    ll noOfComponets;
    Dsu(ll n) {
        par.resize(n);
        rank.resize(n);
        for (ll i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
        noOfComponets = n;
    }
    ll getSuperParent(ll x) {
        if (par[x] == x) return x;
        return par[x] = getSuperParent(par[x]);
    }
    void unite(ll x, ll y) {
        ll superParx = getSuperParent(x);
        ll superPary = getSuperParent(y);
        if (superPary == superParx) return;
        if (rank[superParx] < rank[superPary]) {
            par[superParx] = superPary;
        }
        else if (rank[superParx] > rank[superPary]) {
            par[superPary] = superParx;
        }
        else {
            par[superParx] = superPary;
            rank[superPary]++;
        }
        noOfComponets--;
    }
};

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > v;
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        v.push_back({c, a, b});
    }
    sort(v.begin(), v.end());
    Dsu d(n);
    ll ans = 0;
    for (ll i = 0; i < m; i++) {
        if (d.getSuperParent(v[i][1]) != d.getSuperParent(v[i][2])) {
            d.unite(v[i][1], v[i][2]);
            ans += v[i][0];
        }
    }
    cout << ans << endl;
    return 0;
}