Unique Number III

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;

        // Iterate through every bit position (0 to 31)
        for (int i = 0; i < 32; ++i) {
            int bitSum = 0;
            for (int num : arr) {
                if (num & (1 << i)) {
                    bitSum++;
                }
            }

            // If bitSum % 3 is 1, that bit belongs to the unique number
            if (bitSum % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};
