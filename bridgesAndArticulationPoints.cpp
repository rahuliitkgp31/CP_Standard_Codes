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
ll t;
class graph {
public:
    vector<ll>* adjList;
    vector<ll> disc;  //discovery time of all the nodes
    vector<ll> low;  //lowest time of all the nodes
    set<ll> articulationPts;
    vector<pair<ll, ll> > bridges;
    graph(ll n) {
        adjList = new vector<ll>[n];
        disc.resize(n);
        low.resize(n);
    }
    void addEdge(ll u, ll v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void dfs(ll curr, ll p) {
        disc[curr] = low[curr] = ++t;
        int no_child = 0;
        for (auto& ch : adjList[curr]) {
            if (!disc[ch]) {
                dfs(ch, curr);
                no_child++;
                low[curr] = min(low[curr], low[ch]);
                if ((p != -1) && (low[ch] >= disc[curr])) {
                    articulationPts.insert(curr);
                }
                if (low[ch] > disc[curr]) {
                    bridges.push_back({curr, ch});
                }
            }
            else if (ch != p) {
                low[curr] = min(low[curr], disc[ch]);
            }
        }
        //separate case for root to be an articulation point
        if (p == -1 && no_child >= 2) {
            articulationPts.insert(curr);
        }
    }
};

//Articulation points and bridges
int main() {
    cpp();
    t = 0;
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
    for (auto ele : g.articulationPts) {
        cout << ele << " ";
    }
    cout << endl << endl;
    for (pair<ll, ll>& p : g.bridges) {
        cout << p.first << "->" << p.second << endl;
    }
    return 0;
}


