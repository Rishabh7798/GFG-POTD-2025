Min Cost Climbing Stairs

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        int prev2 = cost[0];  // Cost to reach step 0
        int prev1 = cost[1];  // Cost to reach step 1

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2); // DP transition
            prev2 = prev1;  // Shift values
            prev1 = curr;
        }
        
        return min(prev1, prev2);  // Minimum cost to reach the top
    }
};
