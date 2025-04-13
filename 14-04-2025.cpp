Alien Dictionary

class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, set<char>> adj;  // adjacency list
        unordered_map<char, int> indegree;   // indegree map

        // Initialize all characters from input words in indegree map
        for (const string &word : words) {
            for (char ch : word) {
                indegree[ch] = 0;
            }
        }

        // Build the graph by comparing adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            string &w1 = words[i];
            string &w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool foundDifference = false;
            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    foundDifference = true;
                    break;
                }
            }
            if (!foundDifference && w1.size() > w2.size()) {
                return ""; // Invalid order (prefix case)
            }
        }

        // Kahn's Algorithm (Topological Sort using BFS)
        queue<char> q;
        for (auto &entry : indegree) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }

        string result;
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            result += ch;
            for (char neighbor : adj[ch]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() != indegree.size()) {
            return ""; // Cycle detected or invalid input
        }

        return result;
    }
};
