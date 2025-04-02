Rotten Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0, time = 0;
        
        // Step 1: Store initially rotten oranges & count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        if (freshCount == 0) return 0; // No fresh oranges, return 0
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Step 2: BFS to rot the fresh oranges
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                
                for (size_t d = 0; d < directions.size(); d++) {
                    int dx = directions[d].first, dy = directions[d].second;
                    int nx = x + dx, ny = y + dy;
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;
                        q.push({nx, ny});
                        freshCount--;
                        rotted = true;
                    }
                }
            }
            
            if (rotted) time++;
        }
        
        return (freshCount == 0) ? time : -1;
    }
};
