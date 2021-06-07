#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll partition(ll s, ll e, vector<ll>& v) {
    ll p = v[e];
    ll i = s - 1;
    for (ll j = s; j <= e; j++) {
        if (v[j] <= p) {
            i++;
            swap(v[i], v[j]);
        }
    }
    return i;
}

void quickSort(ll s, ll e, vector<ll>& v) {
    if (s >= e) return;
    ll p = partition(s, e, v);
    quickSort(s, p - 1, v);
    quickSort(p + 1, e, v);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];
    quickSort(0, v.size() - 1, v);
    for (auto& ele : v) cout << ele << " ";
    cout << endl;
    return 0;
}