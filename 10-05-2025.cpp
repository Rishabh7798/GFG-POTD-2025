Longest Subarray with Majority Greater than K

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int, int> first_occurrence;
        int prefix_sum = 0;
        int max_len = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > k) prefix_sum += 1;
            else prefix_sum -= 1;

            if (prefix_sum > 0) {
                // From 0 to i, positive sum
                max_len = i + 1;
            } else {
                if (first_occurrence.find(prefix_sum - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[prefix_sum - 1]);
                }
            }

            // Store only first occurrence of this prefix_sum
            if (first_occurrence.find(prefix_sum) == first_occurrence.end()) {
                first_occurrence[prefix_sum] = i;
            }
        }

        return max_len;
    }
};
