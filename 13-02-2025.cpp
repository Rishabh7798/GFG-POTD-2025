Pair Sum in BST

/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void inorder(Node *root,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    bool findTarget(Node *root, int target) {
        vector<int>ans;
        inorder(root,ans);
        int s=0,e=ans.size()-1;
        while(s<e){
            if(ans[s]+ans[e]==target) return true;
            else if(ans[s]+ans[e]>target) e--;
            else s++;
        }
        return false;
    }
};
