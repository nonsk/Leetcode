class Solution {
public:
    int countPrimes(int n) {
        if(n==1){
            return 0;
        }
        if(n==0){
            return 0;
        }
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<n; i++){
            if(dp[i]==0){
                continue;
            }
            for(int j=i; j<n; j= j+i){
                if(j==i){
                    continue;
                }
                dp[j] = 0;
            }
        }
        int count = 0;
        for(auto it:dp){
            if(it==1){
                count++;
            }
        }
        return count-1;
    }
};