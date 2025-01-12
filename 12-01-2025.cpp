// Trapping Rain Water

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int ans = 0, lmax = 0, rmax = 0;
        int i = 0, j = arr.size() - 1;

        while (i < j) {
            if (arr[i] <= arr[j]) {
                if (lmax < arr[i]) {
                    lmax = arr[i];
                } else {
                    ans += lmax - arr[i];
                }
                i++;
            } else {
                if (rmax < arr[j]) {
                    rmax = arr[j];
                } else {
                    ans += rmax - arr[j];
                }
                j--;
            }
        }

        return ans;
    }
};
