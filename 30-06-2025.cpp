Max min Height

class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        long long low = *min_element(arr.begin(), arr.end());
        long long high = *max_element(arr.begin(), arr.end()) + k;
        int ans = 0;

        auto canAchieve = [&](int target) {
            vector<int> water(n + 1, 0);
            long long used = 0, currWater = 0;

            for (int i = 0; i < n; ++i) {
                currWater += water[i];
                long long currHeight = arr[i] + currWater;
                if (currHeight < target) {
                    int add = target - currHeight;
                    used += add;
                    if (used > k) return false;

                    currWater += add;
                    if (i + w < n) water[i + w] -= add;
                }
            }
            return true;
        };

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAchieve(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
