class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int currentSum) -> bool {
            if (!node) {
                return false;
            }
            currentSum += node->val;
            if (!node->left && !node->right && currentSum == targetSum) {
                return true;
            }
            return dfs(node->left, currentSum) || dfs(node->right, currentSum);
        };
        return dfs(root, 0);
    }
};