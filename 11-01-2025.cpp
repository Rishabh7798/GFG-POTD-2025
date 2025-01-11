// Longest substring with distinct characters

class Solution {
public:
    int longestUniqueSubstr(string s) {
        // Array to store frequency of characters
        vector<int> freq(26, 0);
        int i = 0, j = 0, ans = 0;

        while (j < s.length()) {
            int ch = s[j] - 'a';
            if (freq[ch] > 0) {
                ans = max(ans, j - i);
                while (i < j && s[i] != s[j]) {
                    freq[s[i] - 'a'] = 0;
                    i++;
                }
                i++;
            } else {
                freq[ch]++;
            }
            j++;
        }

        ans = max(ans, j - i);
        return ans;
    }
};
