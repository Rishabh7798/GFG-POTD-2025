Longest Increasing Subsequence

class Solution {
public:
    static int lis(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1); // DP array to store LIS ending at each index
        int maxLIS = 1; // Variable to store max LIS length

        // Compute LIS for each index
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) { // Check increasing condition
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLIS = max(maxLIS, dp[i]); // Update max LIS length
        }

        return maxLIS;
    }
};
