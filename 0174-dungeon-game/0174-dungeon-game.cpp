class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& ans) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        if (i == n - 1 && j == m - 1) {
            return ans[i][j] = max(1, 1 - dungeon[i][j]);
        }
        if (ans[i][j] != INT_MAX) {
            return ans[i][j];
        }
        int health_needed = INT_MAX;
        if (i < n - 1) {
            health_needed = min(health_needed, solve(i + 1, j, dungeon, ans));
        }
        if (j < m - 1) {
            health_needed = min(health_needed, solve(i, j + 1, dungeon, ans));
        }
        ans[i][j] = max(1, health_needed - dungeon[i][j]);
        for(auto it:ans){
            for(auto it2:it){
                cout<<it2<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return ans[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        return solve(0, 0, dungeon, ans);
    }
};
