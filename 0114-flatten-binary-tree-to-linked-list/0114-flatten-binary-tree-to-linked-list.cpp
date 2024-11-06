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
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        TreeNode* f_right = root->right;
        flatten(f_right);
        TreeNode* f_left = root->left;
        flatten(f_left);
        root->left = NULL;
        root->right = f_left;
        TreeNode* temp = root;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        temp->right = f_right;
    }
};