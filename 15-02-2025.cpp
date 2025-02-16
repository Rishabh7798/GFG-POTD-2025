Lowest Common Ancestor in a BST

/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          return solve(root, min(n1->data, n2->data), max(n1->data, n2->data));
      }
      
      Node* solve(Node* root, int n1, int n2) {
          if (!root) return root;
  
          if ((n1 < root->data && n2 > root->data) || root->data == n1 || root->data == n2) {
              return root;
          }
  
          if (n2 < root->data) {
              return solve(root->left, n1, n2);
          }
  
          return solve(root->right, n1, n2);
      }
  };
