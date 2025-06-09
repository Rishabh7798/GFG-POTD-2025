BST with Dead End

/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool solve(Node* root, int minVal, int maxVal) {
        if (!root) return false;

        // Dead end condition: no further nodes can be inserted
        if (minVal == maxVal)
            return true;

        // Check recursively for left and right subtrees
        return solve(root->left, minVal, root->data - 1) || 
               solve(root->right, root->data + 1, maxVal);
    }

    bool isDeadEnd(Node *root) {
        return solve(root, 1, INT_MAX);
    }
};
