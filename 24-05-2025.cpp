Sum of all substrings of a number

class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.length();
        long long result = 0, curr = 0;
        int mod = 1000000007; // Not needed here since result fits in 32-bit int

        for (int i = 0; i < n; ++i) {
            int num = s[i] - '0';
            curr = curr * 10 + num * (i + 1);
            result += curr;
        }

        return static_cast<int>(result);
    }
};
