class Solution {
public:
    int dp[200][200];
    int m;
    int n;
    int helper(int i, int j,vector<vector<int>>& nums) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = 1;
        if(i+1 < m  && nums[i][j] > nums[i+1][j]) {
           dp[i][j] = max(dp[i][j],1 + helper(i+1,j,nums));
        }
        if(i-1 >= 0  && nums[i][j] > nums[i-1][j]) {
           dp[i][j] = max(dp[i][j],1 + helper(i-1,j,nums));
        }
        if(j+1 < n  && nums[i][j] > nums[i][j+1]) {
           dp[i][j] = max(dp[i][j],1 + helper(i,j+1,nums));
        }
        if(j-1 >= 0  && nums[i][j] > nums[i][j-1]) {
           dp[i][j] = max(dp[i][j],1 + helper(i,j-1,nums));
        }
        return dp[i][j];                        
    }
    int longestIncreasingPath(vector<vector<int>>& nums) {
        m = nums.size(); n = nums[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans,helper(i,j,nums));
            }
        }
        return ans;
    }
};