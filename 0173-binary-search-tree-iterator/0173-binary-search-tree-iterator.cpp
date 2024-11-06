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
class BSTIterator {
public:
    int pointer = -1;
    vector<int> inorder;
    void f(TreeNode* root) {
        if (root == NULL) {
            // inorder.push_back(-1);
            return;
        }
        f(root->left);
        inorder.push_back(root->val);
        f(root->right);
    }
    BSTIterator(TreeNode* root) {

        f(root);
        for (auto it : inorder) {
            cout << it << " ";
        }
    }

    int next() {
        pointer++;
        return inorder[pointer];
    }

    bool hasNext() {
        return (pointer + 1 > inorder.size() - 1 ||
                inorder[pointer + 1] == -1)
                   ? false
                   : true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */