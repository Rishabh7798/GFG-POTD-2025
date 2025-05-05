Search in an almost Sorted Array

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) return mid;
            if (mid > low && arr[mid - 1] == target) return mid - 1;
            if (mid < high && arr[mid + 1] == target) return mid + 1;

            // Move the search boundaries
            if (arr[mid] > target) {
                high = mid - 2;
            } else {
                low = mid + 2;
            }
        }

        return -1; 
    }
};
