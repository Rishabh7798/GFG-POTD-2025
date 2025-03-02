K Sized Subarray Maximum

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> res;
        deque<int> dq;  // Deque to store indices

        for (int i = 0; i < n; i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove elements smaller than current one
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            // Add current index to deque
            dq.push_back(i);

            // Store result after the first window is filled
            if (i >= k - 1)
                res.push_back(arr[dq.front()]);
        }

        return res;

    }
};
