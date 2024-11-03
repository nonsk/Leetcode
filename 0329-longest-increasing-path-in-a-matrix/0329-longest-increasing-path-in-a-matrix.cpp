class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1;

        // Define the 4 possible directions: up, right, down, left
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (const auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            // Check if the neighbor is within bounds and greater than current
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, 1 + solve(ni, nj, matrix, dp));
            }
        }

        dp[i][j] = ans;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        
        // Initialize dp array with -1 for memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int answer = 0;

        // Iterate through each cell, calculating the longest increasing path from each
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, solve(i, j, matrix, dp));
            }
        }

        return answer;
    }
};
