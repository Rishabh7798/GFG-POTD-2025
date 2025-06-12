K closest elements

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();
        vector<int> res;

        // Find the insertion point for x
        int left = 0, right = n - 1, pos = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= x) {
                pos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        int l = pos - 1;
        int r = pos;

        while (k > 0) {
            if (l >= 0 && r < n) {
                if (arr[l] == x) {
                    l--;
                    continue;
                }
                if (arr[r] == x) {
                    r++;
                    continue;
                }

                int distL = abs(arr[l] - x);
                int distR = abs(arr[r] - x);

                if (distL < distR) {
                    res.push_back(arr[l--]);
                } else if (distR < distL) {
                    res.push_back(arr[r++]);
                } else {
                    // Tie: prefer larger element
                    if (arr[l] > arr[r]) {
                        res.push_back(arr[l--]);
                    } else {
                        res.push_back(arr[r++]);
                    }
                }
            } else if (l >= 0) {
                if (arr[l] != x)
                    res.push_back(arr[l--]);
                else
                    l--;
            } else if (r < n) {
                if (arr[r] != x)
                    res.push_back(arr[r++]);
                else
                    r++;
            }
            k--;
        }

        return res;
    }
};
