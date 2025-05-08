Missing element of AP

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1;

        // Find minimum adjacent difference (since only 1 element is missing)
        int d = INT_MAX;
        for (int i = 1; i < n; ++i) {
            d = min(d, arr[i] - arr[i - 1]);
        }

        // Traverse to find where the actual difference is more than d
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] != d) {
                return arr[i - 1] + d;
            }
        }

        // If all differences are equal, return next AP term
        return arr[n - 1] + d;
    }
};
