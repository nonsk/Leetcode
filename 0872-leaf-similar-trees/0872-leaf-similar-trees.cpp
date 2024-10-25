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
    void solve(vector<int> &leaf, TreeNode* root1){
        if(root1==NULL){
            return;
        }
        if(root1->right==NULL && root1->left==NULL){
            leaf.push_back(root1->val);
        }
        solve(leaf, root1->left);
        solve(leaf, root1->right);
    
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf;
        vector<int> leaf1;
        solve(leaf, root1);
        solve(leaf1, root2);
        if(leaf==leaf1){

        return true;
        }
        return false;
    }
};