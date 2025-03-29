Gas Station

/*You are required to complete this method*/
class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0, totalCost = 0, startIndex = 0, currentGas = 0;
        int n = gas.size();
        
        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            if (currentGas < 0) {
                startIndex = i + 1;
                currentGas = 0;
            }
        }
        
        return (totalGas >= totalCost) ? startIndex : -1;
    }
};
