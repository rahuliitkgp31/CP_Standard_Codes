//Author rahuliitkgp

/*A thing of beauty is a joy forever,
Its loveliness increases,
it will never pass into nothingness.*/
//Men at Work :)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void cpp() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

ll timer;
class graph {
public:
    vector<ll>* adjList;
    vector<ll> timeIn;
    vector<ll> timeOut;
    graph(ll n) {
        adjList = new vector<ll>[n];
        timeIn.resize(n);
        timeOut.resize(n);
    }
    void addEdge(ll u, ll v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void dfs(ll u, ll p) {
        timeIn[u] = ++timer;
        for (auto ch : adjList[u]) {
            if (ch != p) {
                dfs(ch, u);
            }
        }
        timeOut[u] = timer;
    }
};

//most useful euler tour of tree
int main() {
    cpp();
    timer = 0;
    ll n, m;
    cin >> n >> m;
    graph g(n);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        g.addEdge(u, v);
    }
    g.dfs(0, -1);
    return 0;
}


