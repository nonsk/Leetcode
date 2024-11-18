class Solution {
public:
    bool solve(TreeNode* root, long long minLimit, long long maxLimit) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= minLimit || root->val >= maxLimit) {
            return false;
        }
        return solve(root->left, minLimit, root->val) && solve(root->right, root->val, maxLimit);
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
