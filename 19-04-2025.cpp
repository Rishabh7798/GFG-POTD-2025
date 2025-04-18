Maximum XOR of two numbers in an array

class TrieNode {
public:
    TrieNode* children[2]; // For bits 0 and 1

    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root;

    Solution() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;
            if (node->children[toggledBit]) {
                maxXor |= (1 << i);
                node = node->children[toggledBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }

    int maxXor(vector<int> &arr) {
        int maxResult = 0;

        // Step 1: Insert all elements into Trie
        for (int num : arr) {
            insert(num);
        }

        // Step 2: For each number, find the best XOR with any other number
        for (int num : arr) {
            int currXor = findMaxXOR(num);
            maxResult = max(maxResult, currXor);
        }

        return maxResult;
    }
};
