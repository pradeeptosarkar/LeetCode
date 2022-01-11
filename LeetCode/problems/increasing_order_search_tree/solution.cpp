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
    TreeNode* prev=NULL;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return NULL;
        flatten(root);
        return prev;
    }
    void flatten(TreeNode * root)
    {
        if(!root)
            return;
        flatten(root->right);
        root->right=prev;
        prev=root;
        flatten(root->left);
        root->left=NULL;
    }
};