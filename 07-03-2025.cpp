Longest Palindromic Subsequence

// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Process substrings of length 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Ending index
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // The longest palindromic subsequence is stored in dp[0][n-1]
        return dp[0][n - 1];
    }
};
