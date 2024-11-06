class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        int maxn;
        int maxi;
        vector<vector<int>> dp(n, vector<int>());
        dp[n - 1] = {nums[n - 1]};
        for (int i = n - 2; i >= 0; i--) {
            dp[i].push_back(nums[i]);
            maxn = 1;
            maxi = i;
            vector<int> temp2;
            for (int j = i+1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    if (maxn <= dp[j].size()) {
                        temp2 = dp[j];
                        maxi = j;
                        maxn = dp[j].size();
                    }
                }
            }
            dp[i] = temp2;
            dp[i].push_back(nums[i]);
        }
        maxi = 0;
        maxn = 0;
        for (int i = 0; i < n; i++) {
            if(maxn < dp[i].size()){
                maxn = dp[i].size();
                maxi = i;
            }
        }
        return dp[maxi];
    }
};