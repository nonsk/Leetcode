#include <queue>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));

        
        q.push({0, {0, 0}});
        visited[0][0] = 0; 

        int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!q.empty()) {
            int currentEffort = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            
            if (x == n - 1 && y == m - 1) {
                return currentEffort;
            }

            
            for (auto dir : direction) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    
                    int newEffort = max(currentEffort, abs(heights[newX][newY] - heights[x][y]));

                    
                    if (newEffort < visited[newX][newY]) {
                        visited[newX][newY] = newEffort;
                        q.push({newEffort, {newX, newY}});
                    }
                }
            }
        }

        return 0;  
    }
};
