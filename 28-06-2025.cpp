Counting elements in two arrays

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());  // Step 1: Sort array b
        vector<int> result;

        for (int num : a) {
            // Step 2: Binary search to find upper bound
            int count = upper_bound(b.begin(), b.end(), num) - b.begin();
            result.push_back(count);
        }

        return result;
    }
};
