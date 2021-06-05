#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000001

vector<ll> Primes(N, 1);

void Sieve(){
    Primes[0]=Primes[1]=0;
    for(ll i=2; i<N; i++){
        if(Primes[i]){
            for(ll j=i*i; j<N; j+=i){
                Primes[j]=0;
            }
        }
    }
}
