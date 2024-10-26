class Solution {
public:
    unordered_map<int, int> inorder_map;

    TreeNode* solve(vector<int>& preorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }
        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);
        int root_index = inorder_map[root_val];
        int left_size = root_index - in_start;
        root->left = solve(preorder, pre_start + 1, pre_start + left_size, in_start, root_index - 1);
        root->right = solve(preorder, pre_start + left_size + 1, pre_end, root_index + 1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
