class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector <vector<bool>> dp(n+1, vector<bool>(n+1,false));
        int k = stones[1]-stones[0];
        dp[0][0] = true;
        for(int i =1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                k = stones[i]-stones[j];
                if(k>j+1){
                    break;
                }
                dp[i][k] = dp[j][k-1]||dp[j][k]||dp[j][k+1];
                if(i==n-1 && dp[i][k]){
                    return true;
                }
            }
        }
        return false;

    }
};