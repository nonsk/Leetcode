class Solution {
public:
    int solve(vector<int>& prices, int index, int buy,vector<vector<int>>& dp) {
        if(dp[index][1]!=-1&&buy==1){
            return dp[index][1];
        }
        if(dp[index][0]!=-1&&buy==0){
            return dp[index][0];
        }
        if(index==prices.size()-1&&buy==0){
            return prices[index];
        }
        if(index==prices.size()-1&&buy==1){
            return 0;
        }

        int profit=0;
        if (buy) {
            profit = max(solve(prices, index + 1, 0,dp) - prices[index],
                         solve(prices, index + 1, 1,dp));
                         dp[index][1] = profit;
            return profit;
        } else {
            profit =
                max(solve(prices, index + 1, 0,dp), prices[index]+solve(prices, index + 1, 1,dp));
                dp[index][0] = profit;
            return profit;
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,-1));

        return solve(prices,0, 1,dp);
    }
};