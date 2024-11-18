class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxSide = 0; 
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    int r = dp[i + 1][j];        
                    int d = dp[i][j + 1];        
                    int s = dp[i + 1][j + 1];    
                    dp[i][j] = min({r, d, s}) + 1;
                    maxSide = max(maxSide, dp[i][j]); 
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return maxSide * maxSide;
    }
};
