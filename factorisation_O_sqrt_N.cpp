#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<pair<ll, ll> > findPrimeFactors(ll n) {
    vector<pair<ll, ll> > factors;
    for (ll i = 2; i * i <= n; i++) {
        ll cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        factors.push_back({i, cnt});
    }
    if (n != 1) {
        factors.push_back({n, 1});
    }
    return factors;
}