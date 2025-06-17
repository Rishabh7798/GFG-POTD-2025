Coin Piles

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // prefix[i] = sum of first i elements
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        // suffix[i] = sum of elements from i to n-1
        vector<long long> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + arr[i];

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];
            int limit = minVal + k;

            // Find first element > limit using binary search
            int left = i, right = n - 1, idx = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (arr[mid] > limit) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // coins to remove from left side
            long long coinsToRemove = prefix[i];

            // coins to remove from right side using suffix
            long long numRight = n - idx;
            long long totalRight = suffix[idx];
            coinsToRemove += totalRight - (long long)numRight * limit;

            ans = min(ans, coinsToRemove);
        }

        return (int)ans;
    }
};
