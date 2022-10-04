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
    int res = 0;
    int dfs(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        int leftCheck = 0, rightCheck = 0;
        if(root -> left != NULL and root -> val == root -> left -> val)
            leftCheck = left + 1;
        if(root -> right != NULL and root -> val == root -> right -> val)
            rightCheck = right + 1;
        res = max(res, leftCheck + rightCheck);
        return max(leftCheck, rightCheck);
    }
    
    int longestUnivaluePath(TreeNode* root) 
    {
        dfs(root);
        return res;
    }
};