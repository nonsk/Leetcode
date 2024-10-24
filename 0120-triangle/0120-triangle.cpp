class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<vector<int>>& triangle,int  i,int  layer, int size){
        if(layer==size){
            return 0;
        }
        if(dp[layer][size+1-layer+i]!=INT_MAX){
            return dp[layer][size+1-layer+i];
        }
        int one = triangle[layer][i];
        int two = triangle[layer][i+1];
        int ans = min(one+solve(dp,triangle,i,layer+1, size),two+solve(dp,triangle,i+1,layer+1, size));
        dp[layer][size+1-layer+i] = ans;
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<vector<int>> dp(size, vector<int>(size+1,INT_MAX));
        return triangle[0][0]+solve(dp,triangle, 0,1, size);
    }
};