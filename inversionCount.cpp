#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll merge(ll l, ll r, ll m, vector<ll>& v) {
    vector<ll> left(m - l + 1);
    vector<ll> right(r - m);
    for (ll i = l; i <= m; i++) left[i - l] = v[i];
    for (ll i = m + 1; i <= r; i++) right[i - m - 1] = v[i];
    ll lp = 0, rp = 0, vp = l;
    ll ans = 0;
    while (lp < left.size() && rp < right.size()) {
        if (left[lp] <= right[rp]) {
            v[vp] = left[lp];
            lp++;
        }
        else {
            ans += (left.size() - 1 - lp + 1);
            v[vp] = right[rp];
            rp++;
        }
        vp++;
    }
    while (lp < left.size()) {
        v[vp++] = left[lp++];
    }
    while (rp < right.size()) {
        v[vp++] = right[rp++];
    }
    return ans;
}

ll countInversion(ll l, ll r, vector<ll>&v) {
    if (l >= r) return 0;
    ll mid = l + (r - l) / 2;
    ll left = countInversion(l, mid, v);
    ll right = countInversion(mid + 1, r, v);
    ll x = merge(l, r, mid, v);
    return left + right + x;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];
    cout << countInversion(0, v.size() - 1, v) << endl;
    return 0;
}