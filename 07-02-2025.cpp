// Inorder Traversal

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

// 1) using Recursion
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
    
    private:
    void solve(Node* root, vector<int>& ans) {
        if (root == nullptr)
            return;
        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }
};

---------------------------------------------------------------
// 2) using Stack
class Solution {
    public:
      vector<int> inOrder(Node* root) {
          vector<int> ans;
          stack<Node*> st;
          
          while (root != nullptr) {
              st.push(root);
              root = root->left;
          }
          
          while (!st.empty()) {
              Node* tmp = st.top();
              st.pop();
              ans.push_back(tmp->data);
              
              if (tmp->right != nullptr) {
                  tmp = tmp->right;
                  while (tmp != nullptr) {
                      st.push(tmp);
                      tmp = tmp->left;
                  }
              }
          }
          
          return ans;
      }
  };
