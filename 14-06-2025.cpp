Symmetric Tree

/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isMirror(Node* left, Node* right) {
        // If both are null, they are mirrors
        if (!left && !right) return true;
        
        // If only one is null or values don't match, not mirrors
        if (!left || !right || left->data != right->data) return false;
        
        // Check recursively if left's left and right's right are mirrors,
        // and left's right and right's left are mirrors
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(Node* root) {
        // An empty tree is symmetric
        if (!root) return true;
        
        // Check if left and right subtree are mirrors
        return isMirror(root->left, root->right);
    }
};
