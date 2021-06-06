#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1ll) {
            ans *= a;
        }
        a *= a;
        b >>= 1ll;
    }
    return ans;
}