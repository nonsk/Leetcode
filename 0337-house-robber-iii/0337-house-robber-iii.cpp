class Solution {
public:
    unordered_map<TreeNode*, pair<int, int>> dp;

    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int rob = root->val + left.first + right.first;
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        dp[root] = {notRob, rob};
        return dp[root];
    }
    int rob(TreeNode* root) {
        pair<int, int> result = solve(root);
        return max(result.first, result.second);
    }
};
