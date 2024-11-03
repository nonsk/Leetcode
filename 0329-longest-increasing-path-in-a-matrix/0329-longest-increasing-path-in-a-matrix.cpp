class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        
        int n = matrix.size();
        int m = matrix[0].size();
        int maxPath = 1;
        
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for (const auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(ni, nj, matrix, dp));
            }
        }
        
        dp[i][j] = maxPath;
        return maxPath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int answer = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, dfs(i, j, matrix, dp));
            }
        }
        
        return answer;
    }
};
