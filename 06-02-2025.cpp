// Construct Tree from Inorder & Preorder

// Class that contains the logic to build the binary tree
/*
Definition of the Node class
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
};
*/
class Solution {
  public:
    int findIndex(vector<int> &arr, int start, int target) {
        int i = 0;
        while (arr[start + i] != target)
            i++;
        return i;
    }

    Node *buildUtil(vector<int> &inorder, vector<int> &preorder, int inStart,
                    int preStart, int n) {
        if (n == 0)
            return NULL;

        Node *root = new Node(preorder[preStart]);

        int i = findIndex(inorder, inStart, preorder[preStart]);

        // Recursively construct the left and right subtrees
        root->left = buildUtil(inorder, preorder, inStart, preStart + 1, i);
        root->right =
            buildUtil(inorder, preorder, inStart + i + 1, preStart + i + 1, n - i - 1);

        return root;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        return buildUtil(inorder, preorder, 0, 0, n);
    }
};
