Largest number in K swaps

class Solution {
  public:
    // Helper function to recursively find the maximum number
    void findMaxUtil(string s, int k, string &maxStr, int index) {
        if (k == 0)
            return;

        int n = s.length();
        char maxChar = s[index];

        // Find the maximum digit to the right of current index
        for (int i = index + 1; i < n; i++) {
            if (s[i] > maxChar)
                maxChar = s[i];
        }

        // If a larger digit is found, we will consider swap
        if (maxChar != s[index])
            k--;

        for (int i = n - 1; i >= index; i--) {
            if (s[i] == maxChar) {
                swap(s[i], s[index]);

                if (s.compare(maxStr) > 0)
                    maxStr = s;

                findMaxUtil(s, k, maxStr, index + 1);
                
                // backtrack
                swap(s[i], s[index]);
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        string maxStr = s;
        findMaxUtil(s, k, maxStr, 0);
        return maxStr;
    }
};
