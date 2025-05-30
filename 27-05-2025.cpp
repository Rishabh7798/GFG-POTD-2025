Print leaf nodes from preorder traversal of BST

class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> res;
        int idx = 0;
        findLeaves(preorder, idx, INT_MIN, INT_MAX, res);
        return res;
    }

  private:
    void findLeaves(vector<int>& preorder, int& idx, int minVal, int maxVal, vector<int>& res) {
        if (idx >= preorder.size())
            return;

        int val = preorder[idx];
        if (val < minVal || val > maxVal)
            return;

        idx++;
        int tempIdx = idx;

        // Left subtree
        findLeaves(preorder, idx, minVal, val - 1, res);
        // Right subtree
        findLeaves(preorder, idx, val + 1, maxVal, res);

        // If both left and right recursive calls did not advance idx, then it's a leaf
        if (idx == tempIdx)
            res.push_back(val);
    }
};
