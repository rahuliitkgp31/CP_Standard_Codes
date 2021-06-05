#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 10000001

vector<ll> ps(N, 1);
vector<ll> primes;

void Sieve(){
    ps[0]=ps[1]=0;
    for(ll i=2; i<N; i++){
        if(ps[i]){
            primes.push_back(i);
            for(ll j=i*i; j<N; j+=i){
                ps[j]=0;
            }
        }
    }
}

vector<pair<ll, ll> > findPrimeFactors(ll n){
    vector<pair<ll, ll> > factors;
    for(ll i=0; primes[i]*primes[i]<=n; i++){
        ll cnt = 0;
        while(n%primes[i]==0){
            n/=primes[i];
            cnt++;
        }
        factors.push_back({primes[i], cnt});
    }
    if(n!=1){
        factors.push_back({n, 1});
    }
    return factors;
}