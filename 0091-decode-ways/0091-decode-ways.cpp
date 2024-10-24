class Solution {
public:
    int solve(string s, int i, vector<int>& dp) {
        if (i >= s.size()) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = solve(s, i + 1, dp);

        if (i < s.size() - 1 &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ans += solve(s, i + 2, dp);
        }

        dp[i] = ans;
        return dp[i];
    }

    int numDecodings(string s) {
        if (s.empty())
            return 0;
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};
