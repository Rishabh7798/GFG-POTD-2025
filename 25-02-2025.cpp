Histogram Max Rectangular Area

class Solution {
public:
    int getMaxArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> left(n, -1), right(n, n);
        
        // Finding the left limit
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }
        
        // Clear stack for next computation
        while (!s.empty()) s.pop();
        
        // Finding the right limit
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }
        
        // Calculating the maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, arr[i] * (right[i] - left[i] - 1));
        }
        
        return maxArea;
    }
};
