Palindrome SubStrings

class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.size();
        int count = 0;
        
        // Function to count palindromes centered at left and right
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) // Only count if length >= 2
                    count++;
                left--;
                right++;
            }
        };
        
        // Expand around each character and between characters
        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);     // Odd-length palindromes
            expandAroundCenter(i, i + 1); // Even-length palindromes
        }
        
        return count;
    }
};
