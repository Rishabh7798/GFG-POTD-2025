Unique Number II

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xorAll = 0;
        for (int num : arr) {
            xorAll ^= num;
        }

        // Get rightmost set bit
        int rightmostSetBit = xorAll & -xorAll;

        int x = 0, y = 0;
        for (int num : arr) {
            if (num & rightmostSetBit) {
                x ^= num;
            } else {
                y ^= num;
            }
        }

        if (x < y)
            return {x, y};
        else
            return {y, x};
    }
};
