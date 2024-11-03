class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        int pathsFromRoot = pathSumFromNode(root, (long long) targetSum);
        int pathsFromLeft = pathSum(root->left, targetSum);
        int pathsFromRight = pathSum(root->right, targetSum);
        return pathsFromRoot + pathsFromLeft + pathsFromRight;
    }

private:
    int pathSumFromNode(TreeNode* node, long long targetSum) {
        if (node == NULL) {
            return 0;
        }
        int count = 0;
        if (node->val == targetSum) {
            count += 1;
        }
        count += pathSumFromNode(node->left, targetSum - node->val);
        count += pathSumFromNode(node->right, targetSum - node->val);
        
        return count;
    }
};
