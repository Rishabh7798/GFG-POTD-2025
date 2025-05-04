Smallest distinct window

class Solution {
  public:
    int findSubString(string& str) {
        int n = str.size();
        unordered_set<char> unique_chars(str.begin(), str.end());
        int total_unique = unique_chars.size();

        unordered_map<char, int> window_freq;
        int start = 0, min_len = n + 1, count = 0;

        for (int end = 0; end < n; ++end) {
            window_freq[str[end]]++;

            if (window_freq[str[end]] == 1) {
                count++;  // new unique char found
            }

            while (count == total_unique) {
                min_len = min(min_len, end - start + 1);

                window_freq[str[start]]--;
                if (window_freq[str[start]] == 0) {
                    count--;  // unique char removed
                }
                start++;
            }
        }

        return min_len;
    }
};
