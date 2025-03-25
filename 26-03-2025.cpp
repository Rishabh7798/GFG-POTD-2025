Word Break

// Trie Node
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string &s, int start, TrieNode* node, unordered_map<int, bool> &memo) {
        if (start == s.size()) return true;
        if (memo.count(start)) return memo[start];

        TrieNode* curr = node;
        for (int i = start; i < s.size(); i++) {
            if (!curr->children.count(s[i])) break;
            curr = curr->children[s[i]];
            if (curr->isEnd && search(s, i + 1, node, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
};

class Solution {
public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        Trie trie;
        for (string &word : dictionary) trie.insert(word);
        
        unordered_map<int, bool> memo;
        return trie.search(s, 0, trie.root, memo);
    }
};
