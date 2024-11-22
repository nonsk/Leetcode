

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        
        // Start building the BST using the helper function
        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    // Helper function to build tree in optimal time
    TreeNode* buildTree(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        // Use mid point to divide the array
        int mid = left + (right - left) / 2;
        
        // Create the current node
        TreeNode* root = new TreeNode(nums[mid]);

        // Build left subtree recursively
        root->left = buildTree(nums, left, mid - 1);

        // Build right subtree recursively
        root->right = buildTree(nums, mid + 1, right);

        return root;
    }
};
