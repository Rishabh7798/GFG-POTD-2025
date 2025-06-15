Smallest Divisor

class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;
            
            for (int num : arr) {
                sum += (num + mid - 1) / mid;  // Efficient way to compute ceil(num / mid)
            }
            
            if (sum <= k) {
                ans = mid;       // mid is a potential answer
                high = mid - 1;  // try to find a smaller one
            } else {
                low = mid + 1;   // mid too small, increase it
            }
        }
        
        return ans;
    }
};
