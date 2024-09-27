class Solution {
public:
    int solve(vector<int>& cost, int k, vector<int>& dp){
        if(dp[k]!=-1){
            return dp[k];
        }
        if(k<0){
            return 0;
        }
        if(k<=1){
            return cost[k];
        }
        dp[k] = cost[k]+min(solve(cost, k-1, dp),solve(cost, k-2, dp)); 
        return dp[k];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(solve(cost,cost.size()-1, dp), solve(cost, cost.size()-2, dp));
    }
};