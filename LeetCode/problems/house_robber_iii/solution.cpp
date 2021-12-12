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
    int rob(TreeNode* root) {
         auto v = dfs(root);
        return max(v[0], v[1]);
    }
    
    // Time: O(n)
    // Space: O(h)
    vector<int> dfs(TreeNode * node) {
        if (!node) return {0, 0};
        auto x = dfs(node->left), y = dfs(node->right);
        return {max(x[0], x[1]) + max(y[0], y[1]), x[0] + y[0] + node->val};
    }
};