#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n, m;
    cin >> n >> m;
    map<string, ll> mapp;
    for (ll i = 0; i < m; i++) {
        string x, y;
        ll z;
        cin >> x >> y >> z;
        mapp[x] -= z;
        mapp[y] += z;
    }
    multiset<pair<ll, string> > mm;
    for (map<string, ll>::iterator it = mapp.begin(); it != mapp.end(); it++) {
        mm.insert({it->second, it->first});
    }
    while (!mm.empty()) {
        multiset<pair<ll, string> >::iterator l = mm.begin();
        multiset<pair<ll, string> >::iterator r = --mm.end();
        mm.erase(l);
        mm.erase(r);
        string p1 = l->second;
        string p2 = r->second;
        ll amt1 = l->first;
        ll amt2 = r->first;

        ll commAmt = min(llabs(amt1), amt2);

        amt1 += commAmt;
        amt2 -= commAmt;

        cout << p2 << " gives " << commAmt << " to " << p1 << endl;

        if (amt1 != 0) {
            mm.insert({amt1, p1});
        }
        if (amt2 != 0) {
            mm.insert({amt2, p2});
        }
    }
    return 0;
}