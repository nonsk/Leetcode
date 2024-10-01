/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int max_len(unordered_map<TreeNode*, pair<int, int>>& dp) {
        int maxs = INT_MIN;
        for (auto it : dp) {
            int sum = max(it.second.first + it.second.second + it.first->val,
                          it.first->val);
            sum = max(sum, it.second.first + it.first->val);
            sum = max(sum, it.second.second + it.first->val);
            if (sum > maxs) {
                maxs = sum;
            }
        }
        return maxs;
    }
    int solve(unordered_map<TreeNode*, pair<int, int>>& dp, TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sum_right = solve(dp, root->right);
        int sum_left = solve(dp, root->left);
        dp[root].second = sum_right;
        dp[root].first = sum_left;
        return max(max(sum_right, sum_left) + root->val, root->val);
    }
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> dp;
        int root1 = solve(dp, root);
        cout << solve(dp, root) << endl;
        ;
        for (auto it : dp) {
             cout<<"for "<<it.first->val<<"->"<<it.second.first<<","<<it.second.second<<endl;
        }
        return max(max_len(dp), root1);
    }
};