Count pairs Sum in matrices

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_set<int> mat2Elements;
        
        // Insert all elements of mat2 into a hash set
        for (const auto &row : mat2) {
            for (int num : row) {
                mat2Elements.insert(num);
            }
        }
        
        int count = 0;
        
        // Iterate through mat1 and check if (x - element) exists in mat2
        for (const auto &row : mat1) {
            for (int num : row) {
                if (mat2Elements.find(x - num) != mat2Elements.end()) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
