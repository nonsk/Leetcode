class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n + 1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <=i; j++) {
                if (nums[i - j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[i - j]);
                    if(maxi<dp[i]){
                        maxi = dp[i];
                    }
                }
            }
        }
    return maxi;
    }
};