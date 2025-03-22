Total Decoding Messages

class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0;
        
        int prev2 = 1, prev1 = 1; // DP variables
        
        for (int i = 1; i < n; i++) {
            int current = 0;
            
            // Single-digit decoding (must not be '0')
            if (digits[i] != '0') {
                current += prev1;
            }
            
            // Two-digit decoding (must be between 10 and 26)
            int twoDigit = stoi(digits.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }
            
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};
