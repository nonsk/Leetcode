
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* ans = new TreeNode(preorder[0]);
        int root_index = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> left_inorder(inorder.begin(), inorder.begin() + root_index);
        vector<int> right_inorder(inorder.begin() + root_index + 1, inorder.end());
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
        vector<int> right_preorder(preorder.begin() + 1 + left_inorder.size(), preorder.end());
        ans->left = buildTree(left_preorder, left_inorder);
        ans->right = buildTree(right_preorder, right_inorder);
        return ans;
    }
};
