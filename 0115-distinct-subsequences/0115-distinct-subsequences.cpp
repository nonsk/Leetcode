class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        
        // Base case: An empty string `t` is a subsequence of any prefix of `s`
        for(int j = 0; j <= m; j++) {
            dp[0][j] = 1;
        }
        
        // Fill the dp table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[j-1] == t[i-1]) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % MOD;
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        // Result is the number of distinct subsequences of `t` in `s`
        return static_cast<int>(dp[n][m]);
    }
};
