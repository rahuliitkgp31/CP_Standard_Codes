#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll kadane(vector<ll>& v) {
    ll ans = INT_MIN;
    ll currSum = 0;
    for (ll i = 0; i < v.size(); i++) {
        currSum += v[i];
        ans = max(ans, currSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto& ele : v) cin >> ele;
    cout << kadane(v) << endl;
    return 0;
}
