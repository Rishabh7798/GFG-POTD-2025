Root to Leaf Paths

/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void dfs(Node* node, vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;
        
        // Add current node to the path
        path.push_back(node->data);
        
        // If it's a leaf node, add the path to result
        if (!node->left && !node->right) {
            res.push_back(path);
        } else {
            // Traverse left and right children
            if (node->left)
                dfs(node->left, path, res);
            if (node->right)
                dfs(node->right, path, res);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, path, res);
        return res;
    }
};
