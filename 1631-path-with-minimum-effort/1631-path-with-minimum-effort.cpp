class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        queue<pair<int, pair<int, int>>> q;
        int current;
        int mini = INT_MAX;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        q.push({INT_MAX, {0, 0}});
        while (!q.empty()) {
            current = q.front().first;
            if (mini > current) {
                mini = current;
            }
            auto [x, y] = q.front().second;
            q.pop();
            int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            for (auto dir : direction) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                // cout << newX << "," << newY << endl;
                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    cout << "pushed : "
                         << abs(heights[newX][newY] - heights[x][y]) << " and "
                         << newX << "," << newY << endl;
                    if (visited[newX][newY] == INT_MAX) {
                        q.push({abs(heights[newX][newY] - heights[x][y]),
                                {newX, newY}});
                    }
                    visited[newX][newY] =
                        min(visited[newX][newY],
                            abs(heights[newX][newY] - heights[x][y]));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        return (visited[n - 1][n - 1]==INT_MAX)?0:visited[n - 1][n - 1];
    }
};