class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if (n == 1) return 0;
        if (dp[n] != -1) return dp[n];

        if (n % 2 == 0) {
            dp[n] = 1 + solve(dp, n / 2);
        } else {
            dp[n] = 2 + min(solve(dp, (n + 1)/2), solve(dp, (n - 1)/2)); 
        }

        return dp[n];
    }

    int integerReplacement(int n) {
        vector<int> dp(max(n + 1, 2), -1);
        return solve(dp, n);
    }
};
