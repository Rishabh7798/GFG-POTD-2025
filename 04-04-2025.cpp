Undirected Graph Cycle

class Solution {
public:
    // Find function with path compression
    int find(int node, vector<int>& parent) {
        if (parent[node] == -1) return node;
        return parent[node] = find(parent[node], parent);  // Path compression
    }

    // Union function with union by rank
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = find(u, parent);
        int rootV = find(v, parent);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> parent(V, -1);  // Fixed declaration
        vector<int> rank(V, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int rootU = find(u, parent);
            int rootV = find(v, parent);

            if (rootU == rootV) return true; // Cycle detected
            unionSet(rootU, rootV, parent, rank);
        }
        return false;
    }
};
