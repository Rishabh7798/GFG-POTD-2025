Longest String Chain

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // first sort words by length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        unordered_map<string, int> dp; // Stores longest chain ending at each word
        int max_chain = 1;

        for (string &word : words) {
            dp[word] = 1;  // Each word is at least a chain of length 1
            
            // then check all possible predecessors
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1); // Remove one character
                
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
            max_chain = max(max_chain, dp[word]); // Update the longest chain length
        }

        return max_chain;
    }
};
