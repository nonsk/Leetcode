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
    // dir, r = 1;

    int zigzaglength(int dir, TreeNode* root,
                     unordered_map<TreeNode*, int> &mp) {
        if (mp.find(root) != mp.end()) {

            return mp[root];
        }
        if (root == NULL) {
            return 0;
        }
        if (dir == 1) {
            int temp = zigzaglength(0, root->left, mp) + 1;
            mp[root] = temp;
            return temp;
        }
        if (dir == 0) {
            int temp = zigzaglength(1, root->right, mp) + 1;
            mp[root] = temp;
            return temp;
        }
        return 0;
    }

    int longest(TreeNode* root, unordered_map<TreeNode*, int> &mp) {
        return max(zigzaglength(0, root->left, mp),
                   zigzaglength(1, root->right, mp));
    }
    int longestZigZag(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int max = longest(root, mp);
        TreeNode* traverse;
        while (!q.empty()) {
            traverse = q.front();
            if (traverse->right != NULL) {
                q.push(traverse->right);
                int temp = longest(traverse->right, mp);

                if (max < temp) {
                    max = temp;
                }
                mp[traverse->right] = max;
            }
            if (traverse->left != NULL) {
                q.push(traverse->left);
                int temp = longest(traverse->left, mp);
                if (max < temp) {
                    max = temp;
                }
                mp[traverse->left] = max;
            }
            q.pop();
        }
        return max;
    }
};