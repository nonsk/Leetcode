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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        q.push(root);
        TreeNode* traverse = root;
        int level = 1;
        while (!q.empty()) {

            cout << traverse->val << endl;
            if (level != 0) {
                traverse = q.front();
                if (traverse->left != NULL) {
                    q.push(traverse->left);
                }
                if (traverse->right != NULL) {
                    q.push(traverse->right);
                }

                if (level == 1) {
                    ans.push_back(traverse->val);
                }

                level--;
                q.pop();
            }

            else {
                level = q.size();
                // continue;
            }
        }
        // ans.push_back(traverse->val);
        return ans;
    }
};