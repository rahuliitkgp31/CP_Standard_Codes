#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

class Graph{
public:
    ll n;
    ll m;
    vector<ll>* adjList;
    Graph(ll n, ll m){
        this->n = n;
        this->m = m;
        adjList = new vector<ll>[n];
    }
    void addEdge(ll x, ll y){
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    bool isCovered(ll k){
        ll set = (1<<k)-1;
        ll limit = (1<<n);
        while(set<limit){
            vector<vector<ll> > vis(n, vector<ll>(n));
            ll cnt=0;
            ll v=0;
            for(ll j=1; j<limit; j=j<<1){
                if(set&j){
                    for(ll x=0; x<adjList[v].size(); x++){
                        ll ch = adjList[v][x];
                        if(!vis[v][ch]){
                            vis[v][ch]=1;
                            vis[ch][v]=1;
                            cnt++;
                        }
                    }
                }
                v++;
            }
            if(cnt==m) return true;
            ll c = set&(-set);
            ll r = set+c;
            set = (((r^set)>>2)/c)|r;
        }
        return false;
    }
    ll helper(){
        ll ans=1;
        ll left=1, right=n;
        while(left<=right){
            ll mid = left+(right-left)/2;
            if(isCovered(mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};

int main(){
    ll n, m;
    cin>>n>>m;
    if(m==0){
        cout<<0<<endl;
        return 0;
    }
    Graph g(n, m);
    for(ll i=0; i<m; i++){
        ll x, y;
        cin>>x>>y;
        g.addEdge(--x, --y);
    }
    cout<<g.helper()<<endl;
}
//6 7
//1 2
//1 3
//2 3
//2 4
//3 5
//4 5
//4 6

//6 6
//1 2
//2 3
//1 3
//1 4
//1 5
//1 6
