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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int maxVal = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                maxVal = max(maxVal, top->val);
                if (top->left != nullptr) {
                    q.push(top->left);
                }
                if (top->right != nullptr) {
                    q.push(top->right);
                }
            }
            result.push_back(maxVal);
        }
        return result;
    }
};