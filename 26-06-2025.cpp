Game with String

class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Use max heap to store frequencies
        priority_queue<int> maxHeap;
        for (auto &entry : freq) {
            maxHeap.push(entry.second);
        }

        // Step 3: Remove k characters
        while (k-- > 0 && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            top--; // remove one occurrence
            if (top > 0) {
                maxHeap.push(top);
            }
        }

        // Step 4: Calculate sum of squares of remaining frequencies
        int result = 0;
        while (!maxHeap.empty()) {
            int f = maxHeap.top();
            maxHeap.pop();
            result += f * f;
        }

        return result;
    }
};
