Stickler Thief II

class Solution {
public:
    int robLinear(const vector<int>& nums) {  
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = 0, prev1 = 0;
        for (int num : nums) {
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        return max(robLinear(vector<int>(arr.begin(), arr.end() - 1)), 
                   robLinear(vector<int>(arr.begin() + 1, arr.end())));
    }
};
