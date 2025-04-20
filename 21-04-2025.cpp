Missing in Array

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = (long long)arr.size() + 1;
        long long total_sum = n * (n + 1) / 2;
        long long array_sum = 0;

        for (int num : arr) {
            array_sum += num;
        }

        return (int)(total_sum - array_sum);
    }
};
