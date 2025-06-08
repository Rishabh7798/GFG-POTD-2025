Sum-string

class Solution {
public:
    // Helper function to check if the sum string is valid from a given index
    bool checkSumString(string &s, int start, string num1, string num2) {
        string sum = addStrings(num1, num2);
        int len = sum.size();
        if (start + len > s.size()) return false;
        if (s.substr(start, len) != sum) return false;
        if (start + len == s.size()) return true; // reached the end of the string
        return checkSumString(s, start + len, num2, sum);
    }

    // Helper function to add two number strings
    string addStrings(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; i++) {
            string num1 = s.substr(0, i);
            if (num1.size() > 1 && num1[0] == '0') continue;

            for (int j = 1; i + j < n; j++) {
                string num2 = s.substr(i, j);
                if (num2.size() > 1 && num2[0] == '0') continue;

                if (checkSumString(s, i + j, num1, num2)) return true;
            }
        }
        return false;
    }
};
