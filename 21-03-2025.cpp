Stickler Thief

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev2 = 0, prev1 = arr[0];

        for (int i = 1; i < n; i++) {
            int include = arr[i] + prev2;
            int exclude = prev1;
            int curr = max(include, exclude);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
