Look and Say Pattern

class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string result = "1";
        
        for (int i = 2; i <= n; ++i) {
            string current = "";
            int count = 1;
            
            for (int j = 1; j < result.length(); ++j) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    current += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            // Append the last group
            current += to_string(count) + result.back();
            result = current;
        }
        
        return result;
    }
};
