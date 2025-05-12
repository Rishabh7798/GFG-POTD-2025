nCr

// User function Template for C++
class Solution {
  public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        
        const int MOD = 1000000007;  // Optional if large MOD is needed, otherwise not used as per constraints
        
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, r); j++) {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        
        return dp[n][r];
    }
};
