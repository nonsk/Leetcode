/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          if (nums.empty()) return nullptr;
        
        // Stack to simulate the call stack
        stack<pair<TreeNode**, pair<int, int>>> stk;
        
        // Initializing with the entire range of the array
        TreeNode* root = nullptr;
        stk.push({&root, {0, nums.size() - 1}});
        
        while (!stk.empty()) {
            auto [node, range] = stk.top();
            stk.pop();
            
            int left = range.first, right = range.second;
            if (left > right) continue;
            
            int mid = left + (right - left) / 2;
            *node = new TreeNode(nums[mid]);
            
            // Push right child first (because we're simulating recursion in a stack)
            stk.push({&((*node)->right), {mid + 1, right}});
            // Then push left child
            stk.push({&((*node)->left), {left, mid - 1}});
        }
        
        return root;
    }
};