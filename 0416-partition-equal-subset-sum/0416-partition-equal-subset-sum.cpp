class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for (int i = 0; i < n; i++) {
            total = total + nums[i];
        }
        if (total % 2 == 1||n==1) {
            return false;
        }
        vector<vector<bool>> dp(n, vector<bool>(total / 2 + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= total / 2; j++) {
                if (nums[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            }
        }
        return dp[n - 1][total / 2];
    }
};