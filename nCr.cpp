#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll nCr(ll n, ll r){
    r = min(r, n-r);
    vector<vector<ll> > dp(n+1, vector<ll>(r+1));
    for(ll i=0; i<=n; i++){
        for(ll j=0; j<=min(i, r); j++){
            if(i==j || j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }
    }
    return dp[n][r];
}

int main(){
    ll n, r;
    cin>>n>>r;
    cout<<nCr(n, r)<<endl;
    return 0;
}