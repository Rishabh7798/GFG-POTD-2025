0 - 1 Knapsack Problem

class Solution {
  public:
  // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
         // code here
        int n = val.size();
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; i++) { 
            // Traverse backwards to avoid overwriting
            for (int w = W; w >= wt[i]; w--) { 
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        return dp[W];
    }
};
