Largest Divisible Subset

class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        sort(arr.begin(), arr.end());

        vector<vector<int>> dp(n);
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            vector<int> maxSubset;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && dp[j].size() > maxSubset.size()) {
                    maxSubset = dp[j];
                } else if (arr[i] % arr[j] == 0 && dp[j].size() == maxSubset.size()) {
                    maxSubset = max(maxSubset, dp[j]);
                }
            }
            dp[i] = maxSubset;
            dp[i].push_back(arr[i]);

            if (dp[i].size() > result.size()) {
                result = dp[i];
            } else if (dp[i].size() == result.size()) {
                result = max(result, dp[i]);
            }
        }

        return result;
    }
};
