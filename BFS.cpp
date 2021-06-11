#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Graph {
public:
    ll n;
    vector<ll>* adjList;
    Graph(ll n) {
        this->n = n;
        adjList = new vector<ll>[n];
    }
    void addEdge(ll a, ll b) {
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    void bfs(ll src) {
        vector<ll> vis(n);
        queue<ll> q;
        q.push(src);
        vis[src] = 1;
        while (!q.empty()) {
            ll ele = q.front();
            cout << ele << " ";
            q.pop();
            for (ll i = 0; i < adjList[ele].size(); i++) {
                if (!vis[adjList[ele][i]]) {
                    vis[adjList[ele][i]] = 1;
                    q.push(adjList[ele][i]);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(2, 1);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);
    return 0;
}
