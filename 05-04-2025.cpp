Find the number of islands

class Solution {
  public:
    // Directions for 8-connected grid (vertical, horizontal, diagonal)
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[x][y] = true;

        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // Check bounds and if the next cell is land and unvisited
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] == 'L' && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited);
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};
