Sum of nodes on the longest path

class Solution {
  public:
    void solve(Node* root, int len, int sum, int &maxLen, int &maxSum) {
        if (root == NULL)
            return;
        
        // Add current node to sum and increment path length
        sum += root->data;
        len += 1;
        
        // Check if it is a leaf node
        if (root->left == NULL && root->right == NULL) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
            return;
        }

        // Recur for left and right subtree
        solve(root->left, len, sum, maxLen, maxSum);
        solve(root->right, len, sum, maxLen, maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int maxLen = 0;
        int maxSum = 0;
        solve(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};
