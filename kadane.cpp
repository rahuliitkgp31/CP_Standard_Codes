#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll kadane(vector<ll>& v){
    ll ans = INT_MIN;
    ll currSum = 0;
    ll l = 0;
    ll r = 0;
    pair<ll, ll> pos;
    for(ll i=0; i<v.size(); i++){
        currSum+=v[i];
        if(currSum>ans){
            ans = currSum;
            r=i;
            pos.first=l;
            pos.second=r;
        }
        if(currSum<0){
            l=i+1;
            currSum=0;
        }
    }
    cout<<pos.first<<" "<<pos.second<<endl;
    return ans;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto& ele: v) cin>>ele;
    cout<<kadane(v)<<endl;
    return 0;
}
