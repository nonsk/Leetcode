class Solution {
public:
    int mod = 1e9+7;
    long long solve(int n, int g, int k, vector<vector<int>>&dp ){
        if(n==0 && g==0){
            return 1;
        }
        if(n==0 || g==0){
            return 0;
        }
        if(dp[n][g]!=-1){
            return dp[n][g];
        }
        long long newsong = solve(n-1, g-1,k,dp)*n;
        long long taken = solve(n, g-1,k,dp)*max(0,n-k);
        return dp[n][g]=(newsong+taken)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n+1, vector<int>(goal+1,-1));
        dp[0][0]=1;
        return solve(n, goal, k,dp);
    }
};