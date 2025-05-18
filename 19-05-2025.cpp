Predecessor and Successor

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;
        Node* curr = root;

        // Find predecessor and successor while traversing the tree
        while (curr != nullptr) {
            if (curr->data < key) {
                pre = curr; // possible predecessor
                curr = curr->right;
            } else if (curr->data > key) {
                suc = curr; // possible successor
                curr = curr->left;
            } else {
                // If key is found
                // Find the rightmost node in left subtree (predecessor)
                if (curr->left) {
                    Node* temp = curr->left;
                    while (temp->right)
                        temp = temp->right;
                    pre = temp;
                }
                // Find the leftmost node in right subtree (successor)
                if (curr->right) {
                    Node* temp = curr->right;
                    while (temp->left)
                        temp = temp->left;
                    suc = temp;
                }
                break;
            }
        }

        return {pre, suc};
    }
};
