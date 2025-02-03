// Height of Binary Tree

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        if (node == NULL)
            return -1;
        return 1 + max(height(node->left), height(node->right));
    }
};
