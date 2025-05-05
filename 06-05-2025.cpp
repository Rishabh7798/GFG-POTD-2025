Left View of Binary Tree

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> result;
        if (root == NULL) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();  // Number of nodes at current level

            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                // First node at current level
                if (i == 0)
                    result.push_back(curr->data);

                // Enqueue left and right children
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return result;
    }
};
