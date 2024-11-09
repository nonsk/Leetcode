class Solution {
public:
    int mod = 1e9 + 7;
    int solve(vector<int>&groups, vector<int>&profit , int i ,int p, int n ,int &minProfit , vector<vector<int>>&dp )
    {
        if(i == profit.size() || n == 0)
        {
            if(p >= minProfit)
                return 1;
            return 0;    
        }
        if (dp[i][n] != -1)
            return dp[i][n];
            
        long long exc = solve(groups ,profit , i+1 , p ,  n , minProfit ,dp);
        long long inc = 0 ;
        
        if(groups[i] <= n )
            inc = solve(groups, profit , i+1 , profit[i]+p  , n-groups[i] , minProfit,dp);
         return dp[i][n] = (inc % mod + exc % mod) % mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size = profit.size();
        vector<vector<int>>dp( size , vector<int>(n+1,-1));
        return solve(group, profit , 0 , 0 , n, minProfit , dp);
    }
};