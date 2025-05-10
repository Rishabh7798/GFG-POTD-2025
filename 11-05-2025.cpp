K-th Largest Sum Contiguous Subarray

// User function Template for C++
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        // Min heap to store k largest sums
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Traverse all subarrays and calculate their sums
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += arr[j];
                minHeap.push(sum);
                if (minHeap.size() > k)
                    minHeap.pop(); // Maintain only k largest sums
            }
        }
        
        // The root of minHeap is the k-th largest sum
        return minHeap.top();
    }
};
