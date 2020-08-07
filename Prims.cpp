class graph {
public:
    ll n;
    vector<pair<int, int> >* adjList;
    graph(ll x) {
        n = x;
        adjList = new vector<pair<int, int> >[n];
    }
    void addEdge(int x, int y, int w) {
        adjList[x].push_back({y, w});
        adjList[y].push_back({x, w});
    }
};

int solve(int n, vector<vector<int> > &B) {
    graph g(n);
    for (auto& vec : B) {
        g.addEdge(--vec[0], --vec[1], vec[2]);
    }
    vector<int> vis(n);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, 0});
    int ans = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int node = p.second;
        int wei = p.first;
        if (vis[node]) continue;
        vis[node] = 1;
        ans += wei;
        for (auto ch : g.adjList[node]) {
            if (vis[ch.first] == 0) {
                pq.push({ch.second, ch.first});
            }
        }
    }
    return ans;
}
