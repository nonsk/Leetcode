class Solution {
public:
    int mod = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < group.size(); i++) {
            int members = group[i];
            int profitGain = profit[i];
            for (int j = n; j >= members; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    int newProfit = min(k + profitGain, minProfit);
                    dp[j][newProfit] = (dp[j][newProfit] + dp[j - members][k]) % mod;
                }
            }
        }
        int totalSchemes = 0;
        for (int j = 0; j <= n; j++) {
            totalSchemes = (totalSchemes + dp[j][minProfit]) % mod;
        }
        return totalSchemes;
    }
};
