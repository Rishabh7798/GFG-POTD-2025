Find rectangle with corners as 1

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size();
        
        // Iterate over all pairs of rows
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int count = 0;
                // Count columns where both rows have 1
                for (int col = 0; col < m; ++col) {
                    if (mat[i][col] == 1 && mat[j][col] == 1) {
                        count++;
                        if (count >= 2) return true; // rectangle found
                    }
                }
            }
        }
        
        return false;
    }
};
