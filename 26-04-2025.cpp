Is Binary Tree Heap

// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
public:
    // Function to count total number of nodes
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Function to check completeness of binary tree
    bool isCBT(Node* root, int index, int totalNodes) {
        if (!root) return true;
        if (index >= totalNodes) return false;
        return isCBT(root->left, 2 * index + 1, totalNodes) &&
               isCBT(root->right, 2 * index + 2, totalNodes);
    }

    // Function to check the max-heap property
    bool isMaxOrder(Node* root) {
        if (!root->left && !root->right) return true;

        if (root->right == nullptr) {
            return (root->data >= root->left->data) && isMaxOrder(root->left);
        } else {
            bool leftValid = root->data >= root->left->data;
            bool rightValid = root->data >= root->right->data;
            return (leftValid && rightValid &&
                    isMaxOrder(root->left) &&
                    isMaxOrder(root->right));
        }
    }

    // Main function to check if binary tree is a heap
    bool isHeap(Node* tree) {
        int totalNodes = countNodes(tree);
        return isCBT(tree, 0, totalNodes) && isMaxOrder(tree);
    }
};
