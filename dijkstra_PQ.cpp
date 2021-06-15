#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph{
public:
    vector<pair<ll, ll> >* adjList;
    ll n;
    Graph(ll n){
        this->n = n;
        adjList = new vector<pair<ll, ll> >[n];
    }
    void addEdge(ll a, ll b, ll w){
        adjList[a].push_back({b, w});
    }
    ll dijkstra(ll src, ll des){
        vector<ll> dis(n, INT_MAX);
        vector<ll> vis(n);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll> > > pq;
        pq.push({0, src});
        dis[src]=0;
        while(!pq.empty()){
            ll node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(ll i=0; i<adjList[node].size(); i++){
                ll ch = adjList[node][i].first;
                ll edgeWei = adjList[node][i].second;
                if(dis[ch]>dis[node]+edgeWei){
                    dis[ch]=dis[node]+edgeWei;
                    pq.push({dis[ch], ch});
                }
            }
        }
        return dis[des];
    }
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        Graph g(n);
        for(ll i=0; i<m; i++){
            ll a, b, c;
            cin>>a>>b>>c;
            --a, --b;
            g.addEdge(a, b, c);
        }
        ll src, des;
        cin>>src>>des;
        --src, --des;
        ll ans = g.dijkstra(src, des);
        if(ans==INT_MAX){
            cout<<"NO"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
