Level Order in spiral form

/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> result;
        if (!root) return result;

        stack<Node*> s1; // For levels to be printed right to left
        stack<Node*> s2; // For levels to be printed left to right

        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            // Process s1: right to left
            while (!s1.empty()) {
                Node* temp = s1.top();
                s1.pop();
                result.push_back(temp->data);
                
                // Push children in reverse order for next level
                if (temp->right) s2.push(temp->right);
                if (temp->left) s2.push(temp->left);
            }

            // Process s2: left to right
            while (!s2.empty()) {
                Node* temp = s2.top();
                s2.pop();
                result.push_back(temp->data);
                
                // Push children in reverse order for next level
                if (temp->left) s1.push(temp->left);
                if (temp->right) s1.push(temp->right);
            }
        }

        return result;
    }
};
