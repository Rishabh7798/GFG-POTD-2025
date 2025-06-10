Exactly one swap

class Solution {
  public:
    int countStrings(string &s) {
        int n = s.size();
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        // Total possible swaps (i < j): n * (n - 1) / 2
        long long total_swaps = (1LL * n * (n - 1)) / 2;

        // Subtract duplicate swaps (those that result in same string)
        long long duplicate_swaps = 0;
        for (auto &entry : freq) {
            long long f = entry.second;
            duplicate_swaps += (f * (f - 1)) / 2;
        }

        long long distinct = total_swaps - duplicate_swaps;

        // If there's any duplicate character, then original string can appear again via a swap
        if (distinct < total_swaps) {
            return distinct + 1;  // Include original
        } else {
            return distinct;
        }
    }
};
