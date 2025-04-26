Multiply two strings

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Remove leading zeros
        int i = 0, j = 0;
        while (i < s1.size() && s1[i] == '0') i++;
        while (j < s2.size() && s2[j] == '0') j++;
        s1 = s1.substr(i);
        s2 = s2.substr(j);
        
        if (s1.empty() || s2.empty()) return "0";  // if any becomes empty after removing zeros
        
        // Check for negative signs
        bool neg = false;
        if (s1[0] == '-') {
            neg = !neg;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            neg = !neg;
            s2 = s2.substr(1);
        }
        
        int n = s1.size();
        int m = s2.size();
        vector<int> result(n + m, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert result to string
        string ans = "";
        int k = 0;
        while (k < result.size() && result[k] == 0) k++; // skip leading zeros
        for (; k < result.size(); k++) {
            ans.push_back(result[k] + '0');
        }
        
        if (ans.empty()) return "0";  // in case of all zeros
        
        if (neg) ans = "-" + ans;
        return ans;
    }
};
