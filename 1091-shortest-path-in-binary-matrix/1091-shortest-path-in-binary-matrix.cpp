class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;  // No path if start or end is blocked.
        }

        // Special case for a single cell grid
        if (n == 1 && grid[0][0] == 0) {
            return 1;
        }

        // Directions for 8 possible moves
        vector<pair<int, int>> directions = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

        // Two queues for bidirectional BFS
        queue<pair<int, int>> qStart, qEnd;
        qStart.push({0, 0});
        qEnd.push({n - 1, n - 1});
        
        // Start and end distances
        vector<vector<int>> distStart(n, vector<int>(n, -1));  // Distance from start
        vector<vector<int>> distEnd(n, vector<int>(n, -1));    // Distance from end
        
        distStart[0][0] = 1;
        distEnd[n - 1][n - 1] = 1;

        while (!qStart.empty() && !qEnd.empty()) {
            // Expand BFS from the start side
            int result = bfs(qStart, distStart, distEnd, grid, directions, n);
            if (result != -1) return result;

            // Expand BFS from the end side
            result = bfs(qEnd, distEnd, distStart, grid, directions, n);
            if (result != -1) return result;
        }

        // If no path is found
        return -1;
    }

private:
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& distThis, vector<vector<int>>& distOther,
            vector<vector<int>>& grid, vector<pair<int, int>>& directions, int n) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            int currDist = distThis[x][y];

            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check if the new position is valid
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    // If we encounter a cell visited by the opposite BFS direction, we have found a path
                    if (distOther[newX][newY] != -1) {
                        return currDist + distOther[newX][newY];
                    }

                    // If this cell is unvisited, mark it and continue BFS
                    if (distThis[newX][newY] == -1) {
                        distThis[newX][newY] = currDist + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return -1;
    }
};
