Case-specific Sorting of Strings

class Solution {
  public:
    string caseSort(string& s) {
        string lower, upper;

        // Step 1: Separate lowercase and uppercase characters
        for (char c : s) {
            if (islower(c))
                lower.push_back(c);
            else
                upper.push_back(c);
        }

        // Step 2: Sort both lowercase and uppercase characters
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        // Step 3: Merge back into original structure based on case
        int li = 0, ui = 0;
        string result = s;

        for (int i = 0; i < s.length(); ++i) {
            if (islower(s[i])) {
                result[i] = lower[li++];
            } else {
                result[i] = upper[ui++];
            }
        }

        return result;
    }
};
