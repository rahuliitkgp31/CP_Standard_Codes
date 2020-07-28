
class graph {
public:
    vector<pair<int, int> >* adjList;
    vector<int> dis;
    int n;
    vector<int> visited;
    graph(int x) {
        n = x;
        adjList = new vector<pair<int, int> >[x];
        dis.resize(x);
        visited.resize(x);
    }
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    void dijkstra(int src) {
        for (auto& ele : dis) ele = INT_MAX;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  pq;
        pq.push({0, src});
        dis[src] = 0;
        while (!pq.empty()) {
            pair<int, int> node = pq.top();
            pq.pop();
            if (visited[node.second]) continue;
            visited[node.second] = 1;
            for (auto ch : adjList[node.second]) {
                if (dis[ch.first] > dis[node.second] + ch.second) {
                    dis[ch.first] = dis[node.second] + ch.second;
                    pq.push({dis[ch.first], ch.first});
                }
            }
        }
    }
};