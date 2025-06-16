Equalize the Towers

class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int, int>> tower(n);
        
        // Pair heights with their corresponding costs
        for (int i = 0; i < n; ++i) {
            tower[i] = {heights[i], cost[i]};
        }

        // Sort by heights
        sort(tower.begin(), tower.end());

        // Compute total cost
        long long totalWeight = 0;
        for (auto& t : tower) {
            totalWeight += t.second;
        }

        // Find weighted median
        long long cumulative = 0;
        int medianHeight = 0;
        for (int i = 0; i < n; ++i) {
            cumulative += tower[i].second;
            if (cumulative >= (totalWeight + 1) / 2) {
                medianHeight = tower[i].first;
                break;
            }
        }

        // Compute minimum cost to equalize all towers to medianHeight
        long long minCost = 0;
        for (int i = 0; i < n; ++i) {
            minCost += 1LL * abs(heights[i] - medianHeight) * cost[i];
        }

        return minCost;
    }
};
