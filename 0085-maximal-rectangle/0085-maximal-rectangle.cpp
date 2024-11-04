class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = (j == 0 ? 1 : dp[i][j - 1] + 1);
                    int width = dp[i][j];
                    for (int k = i; k >= 0; k--) {
                        width = min(width, dp[k][j]);
                        int height = i - k + 1;
                        maxArea = max(maxArea, width * height);
                    }
                }
            }
        }
        
        return maxArea;
    }
};
