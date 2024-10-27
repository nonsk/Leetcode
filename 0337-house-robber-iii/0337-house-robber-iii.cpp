class Solution {
public:
    unordered_map<TreeNode*, unordered_map<bool, int>> dp;
    int solve(bool can, TreeNode* root) {
        if (root == NULL) {
            dp[root][can] = 0;
            return 0;
        }
        if (dp[root].find(can) != dp[root].end()) {
            return dp[root][can];
        }
        if (!can) {
            dp[root][can] = solve(true, root->left) + solve(true, root->right);
            return dp[root][can];
        }
        dp[root][1] = root->val + solve(false, root->left) + solve(false, root->right);
        dp[root][0] = solve(true, root->left) + solve(true, root->right);
        return max(dp[root][0],dp[root][1]);
    }
    int rob(TreeNode* root) { return solve(true, root); }
};