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
    void make(TreeNode* root, vector<int> &tree, int check, int &ans){
        if(root==NULL){
            return ;
        }
        cout<<root->val<<","<<check<<","<<ans<<endl;
        tree.push_back(root->val);
        if(root->val>=check){
            ans++;
        }
        make(root->right, tree, max(check,root->val), ans);
        make(root->left, tree, max(check,root->val), ans);
        return;
    }
    int goodNodes(TreeNode* root) {
        vector<int> tree;
        int check = INT_MIN;
        int ans = 0;
        make(root,tree,check, ans);
        for(auto it: tree){
            cout<<it<<" ";
        }
        return ans;
    }
};