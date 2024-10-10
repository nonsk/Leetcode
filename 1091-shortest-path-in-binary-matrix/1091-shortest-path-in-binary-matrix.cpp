class Solution {
public:
    void travel(int& count, int i, int j, vector<vector<int>>& path, 
                vector<vector<int>>& grid, int n) {
        if (i >= n || j >= n || i < 0 || j < 0) {
            return;
        }
        if (path[i][j] != INT_MAX) {
            return;
        }
        path[i][j] = min(path[i][j], count);
        count++;
        if (i > 0 && grid[i - 1][j] == 0) {
            travel(count, i - 1, j, path, grid, n);
        }
        if (i > 0 && j < n - 1 && grid[i - 1][j + 1] == 0) {
            travel(count, i - 1, j + 1, path, grid, n);
        }
        if (j < n - 1 && grid[i][j + 1] == 0) {
            travel(count, i, j + 1, path, grid, n);
        }
        if (i < n - 1 && j < n - 1 && grid[i + 1][j + 1] == 0) {
            travel(count, i + 1, j + 1, path, grid, n);
        }
        if (i < n - 1 && grid[i + 1][j] == 0) {
            travel(count, i + 1, j, path, grid, n);
        }
        if (j > 0 && grid[i][j - 1] == 0) {
            travel(count, i, j - 1, path, grid, n);
        }
        if (i < n - 1 && j > 0 && grid[i + 1][j - 1] == 0) {
            travel(count, i + 1, j - 1, path, grid, n);
        }
        if (j > 0 && i > 0 && grid[i - 1][j - 1] == 0) {
            travel(count, i - 1, j - 1, path, grid, n);
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1; 
        }

        vector<vector<int>> path(n, vector<int>(n, INT_MAX));  
        path[n - 1][n - 1] = 1; 
        
        queue<pair<int, int>> q; 
        q.push({n - 1, n - 1});
        int directions[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int currDist = path[x][y];
            
            for (auto& dir : directions) {
                int newX = x + dir[0], newY = y + dir[1];
                
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0 && path[newX][newY] == INT_MAX) {
                    path[newX][newY] = currDist + 1;
                    q.push({newX, newY});
                }
            }
        }
        return path[0][0] == INT_MAX ? -1 : path[0][0];
    }
};
