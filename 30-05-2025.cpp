Closest Neighbour in BST

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int result = -1; // Assuming no node value is negative (can change to INT_MIN if needed)
        while (root != NULL) {
            if (root->data == k) {
                return k;
            }
            else if (root->data < k) {
                result = root->data;  // potential answer
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return result;
    }
};
