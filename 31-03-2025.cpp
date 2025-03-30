Maximize partitions in a String

class Solution {
public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        
        // Store the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        int partitions = 0, maxLast = 0;
        
        // Iterate through the string and find partition points
        for (int i = 0; i < s.size(); i++) {
            maxLast = max(maxLast, lastIndex[s[i]]);
            // If current index reaches max last occurrence, create a partition
            if (i == maxLast) {  
                partitions++;
            }
        }

        return partitions;
    }
};
