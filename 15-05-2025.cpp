Substrings with same first and last characters

class Solution {
  public:
    int countSubstring(string &s) {
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int count = 0;
        for (int f : freq) {
            if (f > 0) {
                count += f * (f + 1) / 2;
            }
        }
        
        return count;
    }
};
