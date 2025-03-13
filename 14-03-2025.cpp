Coin Change (Count Ways)

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<int> dp(sum + 1, 0);
        // There's one way to make sum = 0, by choosing nothing.
        dp[0] = 1; 
        
        for (int coin : coins) {
            for (int j = coin; j <= sum; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[sum];
    }
};
