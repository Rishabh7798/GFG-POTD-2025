Koko Eating Bananas

class Solution {
  public:
    bool canEatAll(vector<int>& arr, int k, int s) {
        int hours = 0;
        for (int bananas : arr) {
            hours += (bananas + s - 1) / s; // ceil(bananas / s)
            if (hours > k) return false;    // Early exit if already exceeds
        }
        return hours <= k;
    }

    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEatAll(arr, k, mid)) {
                result = mid;      // Try to find smaller valid s
                high = mid - 1;
            } else {
                low = mid + 1;     // s is too small
            }
        }

        return result;
    }
};
