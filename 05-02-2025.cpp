// Mirror Tree

// Full function Template for C++
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* node) {
        if(!node) return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }
};
