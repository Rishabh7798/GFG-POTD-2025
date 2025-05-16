Smallest range in K lists

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        int n = arr[0].size();

        // Min heap to store (value, row index, col index)
        typedef tuple<int, int, int> T;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        int maxVal = INT_MIN;
        // Initialize the heap with first element of each list
        for (int i = 0; i < k; i++) {
            minHeap.push(make_tuple(arr[i][0], i, 0));
            maxVal = max(maxVal, arr[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while (!minHeap.empty()) {
            T t = minHeap.top();
            minHeap.pop();

            int minVal = get<0>(t);
            int row = get<1>(t);
            int col = get<2>(t);

            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // If there are more elements in the same row
            if (col + 1 < n) {
                int nextVal = arr[row][col + 1];
                minHeap.push(make_tuple(nextVal, row, col + 1));
                maxVal = max(maxVal, nextVal);
            } else {
                break; // One list is exhausted
            }
        }

        return {rangeStart, rangeEnd};
    }
};
