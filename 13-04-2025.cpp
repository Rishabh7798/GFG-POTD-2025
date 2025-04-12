Clone an Undirected Graph

// User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> cloneMap;
        return dfs(node, cloneMap);
    }

  private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloneMap) {
        // If the node is already cloned, return the clone
        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }

        // Clone the current node
        Node* cloneNode = new Node(node->val);
        cloneMap[node] = cloneNode;

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(neighbor, cloneMap));
        }

        return cloneNode;
    }
};
