Minimum sum

class Solution {
  public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += (num1[i--] - '0');
            if (j >= 0) sum += (num2[j--] - '0');
            carry = sum / 10;
            result += (sum % 10 + '0');
        }
        reverse(result.begin(), result.end());
        // Remove any leading zeroes
        int pos = result.find_first_not_of('0');
        return (pos == string::npos) ? "0" : result.substr(pos);
    }

    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        string num1 = "", num2 = "";
        
        for (int i = 0; i < arr.size(); ++i) {
            if (i % 2 == 0)
                num1 += (arr[i] + '0');
            else
                num2 += (arr[i] + '0');
        }

        return addStrings(num1, num2);
    }
};
