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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int sum = 0;
        TreeNode* traverse = root;
        // (root == NULL) ? return 0 : q.push(root);
        if (root == NULL) {
            return 0;
        }
        q.push(root);
        int level = 1;
        int whichLevel = 1;
        int max = root->val;
        int maxLevel = 1;

        while (!q.empty()) {
            //////////////
            cout << q.front()->val << endl;
            ///////////
            if (level == 0) {
                if (max < sum) {
                    max = sum;
                    maxLevel = whichLevel;
                }
                sum = 0;
                whichLevel++;
                level = q.size();
                cout << "level" << level << endl;
            } else {
                traverse = q.front();
                if (traverse->left != NULL) {
                    q.push(traverse->left);
                }
                if (traverse->right != NULL) {
                    q.push(traverse->right);
                }
                q.pop();
                level--;
                sum = sum + traverse->val;
            }
        }
        if (max < sum) {
            max = sum;
            maxLevel = whichLevel;
        }
        return maxLevel;
    }
};