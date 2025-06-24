Lexicographically Largest String After K Deletions

class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int keep = n - k;
        string stack;
        
        for (char c : s) {
            // Remove smaller characters from the end if we still can delete
            while (!stack.empty() && k > 0 && stack.back() < c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }

        // Return only the first (n - k) characters
        return stack.substr(0, keep);
    }
};
