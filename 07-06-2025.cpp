Longest Span in two Binary Arrays

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> prefixDiffMap;
        int maxLen = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; ++i) {
            // Compute the difference between the two arrays at index i
            int diff = a1[i] - a2[i];
            prefixSum += diff;

            // If prefixSum is 0, the span from 0 to i has equal sum
            if (prefixSum == 0)
                maxLen = i + 1;

            // If this prefixSum has been seen before, update maxLen
            if (prefixDiffMap.find(prefixSum) != prefixDiffMap.end()) {
                maxLen = max(maxLen, i - prefixDiffMap[prefixSum]);
            } else {
                // Store the first occurrence of this prefixSum
                prefixDiffMap[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
