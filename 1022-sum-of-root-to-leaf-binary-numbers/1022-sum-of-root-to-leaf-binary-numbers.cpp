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
    int dfs(TreeNode* node, int currentValue) {
        if (node == nullptr)
            return 0;

        // Build binary number
        currentValue = (currentValue << 1) | node->val;

        // If leaf node
        if (node->left == nullptr && node->right == nullptr)
            return currentValue;

        return dfs(node->left, currentValue) + 
               dfs(node->right, currentValue);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};