class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1;
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + directions[k][0];
            int nj = j + directions[k][1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (matrix[ni][nj] > matrix[i][j]) {
                    ans = max(ans, 1 + solve(ni, nj, matrix, dp));
                }
            }
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int answer = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, solve(i, j, matrix, dp));
            }
        }
        return answer;
    }
};
