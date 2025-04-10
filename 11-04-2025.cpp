Dijkstra Algorithm

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }

        // Distance vector initialized to infinity
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Min-heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            // Traverse neighbors
            for (int i = 0; i < adj[node].size(); ++i) {
                int adjNode = adj[node][i].first;
                int weight = adj[node][i].second;

                // Relaxation step
                if (dist[adjNode] > d + weight) {
                    dist[adjNode] = d + weight;
                    pq.push(make_pair(dist[adjNode], adjNode));
                }
            }
        }

        return dist;
    }
};
