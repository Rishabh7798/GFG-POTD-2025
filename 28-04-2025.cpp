Maximum sum of Non-adjacent nodes

class Solution {
  public:
    // Helper function returning a pair {including_current_node, excluding_current_node}
    pair<int, int> solve(Node* root) {
        if (!root) return {0, 0};  // Base case
        
        // Solve for left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        // If we include current node, we can't include its children
        int include = root->data + left.second + right.second;
        
        // If we exclude current node, we can take max of including or excluding its children
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }
    
    int getMaxSum(Node *root) {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second); // Return the maximum of including or excluding the root
    }
};
