All Palindromic Partitions

class Solution {
  public:
    // Helper function to check if a string is palindrome
    bool isPalindrome(const string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }

    // Backtracking function to generate all palindromic partitions
    void backtrack(int start, string &s, vector<string> &path, vector<vector<string>> &result) {
        if(start == s.length()) {
            result.push_back(path);
            return;
        }

        for(int end = start; end < s.length(); ++end) {
            if(isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, path, result);
                path.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, path, result);
        return result;
    }
};
