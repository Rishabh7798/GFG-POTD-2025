Bitonic Point

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the bitonic point
            if ((mid == 0 || arr[mid - 1] < arr[mid]) &&
                (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                return arr[mid];
            }
            // Move to the right part
            else if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            // Move to the left part
            else {
                high = mid - 1;
            }
        }

        return -1; // This line should never be reached due to problem constraints
    }
};
