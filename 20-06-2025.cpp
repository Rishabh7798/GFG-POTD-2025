Group Balls by Sequence

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        if (arr.size() % k != 0) return false; // total elements must be divisible by k
        
        map<int, int> count;
        for (int num : arr) {
            count[num]++;
        }
        
        while (!count.empty()) {
            int start = count.begin()->first;
            for (int i = 0; i < k; ++i) {
                int curr = start + i;
                if (count[curr] == 0) return false;
                count[curr]--;
                if (count[curr] == 0) {
                    count.erase(curr);
                }
            }
        }
        
        return true;
    }
};
