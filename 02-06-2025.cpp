Unique Paths in a Grid

class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // If start or end cell is blocked
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;
        
        vector<int> dp(m, 0);
        
        for (int i = 0; i < n; ++i) {
            vector<int> new_dp(m, 0);
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    new_dp[j] = 0; // Blocked cell
                } else if (i == 0 && j == 0) {
                    new_dp[j] = 1; // Starting cell
                } else {
                    int up = i > 0 ? dp[j] : 0;
                    int left = j > 0 ? new_dp[j - 1] : 0;
                    new_dp[j] = up + left;
                }
            }
            dp = new_dp;
        }
        
        return dp[m - 1];
    }
};
