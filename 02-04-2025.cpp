BFS of graph

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> result;
        int V = adj.size();
        vector<bool> visited(V, false);
        queue<int> q;
        
        // Start BFS from node 0
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            // Traverse all adjacent nodes in given order
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return result;
    }
};
