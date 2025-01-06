// Sum Pair closest to target

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int st = 0, end = arr.size() - 1, currClose = INT_MAX;

        while (st < end) {
            int sum = arr[st] + arr[end];
            if (abs(target - sum) < currClose) {
                currClose = abs(target - sum);
                ans.clear();
                ans.push_back(arr[st]);
                ans.push_back(arr[end]);
            }

            if (sum < target) {
                st++;
            } else if (sum > target) {
                end--;
            } else {
                return ans; // Exact match found
            }
        }

        return ans;
    }
};
