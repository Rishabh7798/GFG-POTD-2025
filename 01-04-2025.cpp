DFS of Graph

class Solution {
  public:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> result;
        
        dfsHelper(0, adj, visited, result);
        return result;
    }
};
