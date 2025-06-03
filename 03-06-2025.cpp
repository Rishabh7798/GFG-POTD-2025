Substrings with K Distinct

class Solution {
public:
    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }

private:
    int atMostK(const string& s, int k) {
        if (k == 0) return 0;
        
        vector<int> freq(26, 0); // For lowercase letters
        int left = 0, right = 0, count = 0, distinct = 0;
        
        while (right < s.size()) {
            if (freq[s[right] - 'a'] == 0) distinct++;
            freq[s[right] - 'a']++;
            
            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) distinct--;
                left++;
            }
            
            count += right - left + 1;
            right++;
        }
        
        return count;
    }
};
