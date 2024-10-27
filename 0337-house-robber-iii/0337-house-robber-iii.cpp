class Solution {
public:
    unordered_map<TreeNode*, unordered_map<bool, int>> dp;
    int solve(bool can, TreeNode* root) {
        if (root == NULL) {
            dp[root][can] = 0;
            return 0;
        }
        if (dp[root].count(can)) {
            return dp[root][can];
        }
        if (!can) {
            dp[root][can] = solve(true, root->left) + solve(true, root->right);
            return dp[root][can];
        }
        dp[root][can] = max(root->val + solve(false, root->left) +
                                solve(false, root->right),
                            solve(true, root->left) + solve(true, root->right));
        return dp[root][can];
    }
    int rob(TreeNode* root) { return solve(true, root); }
};