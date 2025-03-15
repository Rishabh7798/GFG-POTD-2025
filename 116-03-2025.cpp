Minimum Jumps

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n <= 1) return 0;  // Already at the last index
        if (arr[0] == 0) return -1;  // Cannot move anywhere

        int maxReach = arr[0];  // Farthest reachable index
        int steps = arr[0];     // Steps remaining in the current jump
        int jumps = 1;          // Minimum jumps taken

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;  // Reached last index
            
            maxReach = max(maxReach, i + arr[i]);  // Update the farthest reach
            
            steps--;  // Use a step to move forward

            if (steps == 0) {  // Need to jump again
                jumps++;
                if (i >= maxReach) return -1;  // Can't move further
                
                steps = maxReach - i;  // Update steps for the next jump
            }
        }
        
        return -1;  // If never reached last index
    }
};
