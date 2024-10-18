class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        if (obstacleGrid[n - 1][m - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        vector<vector<long>> dp(n, vector<long>(m, -1));
        int i = n - 1;
        int j;
        dp[n - 1][m - 1] = 1;
        for (int j = m - 2; j >= 0; j--) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i][j + 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (j == m - 1) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};