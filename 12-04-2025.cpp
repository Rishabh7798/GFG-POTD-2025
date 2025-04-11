Flood fill Algorithm

class Solution {
  public:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor, int n, int m) {
        // Boundary and color checks
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != oldColor)
            return;
        
        image[i][j] = newColor;

        // Recursive DFS in 4 directions
        dfs(image, i + 1, j, oldColor, newColor, n, m);
        dfs(image, i - 1, j, oldColor, newColor, n, m);
        dfs(image, i, j + 1, oldColor, newColor, n, m);
        dfs(image, i, j - 1, oldColor, newColor, n, m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];

        // Avoid unnecessary work if the color is already the target
        if (oldColor != newColor) {
            dfs(image, sr, sc, oldColor, newColor, n, m);
        }

        return image;
    }
};
