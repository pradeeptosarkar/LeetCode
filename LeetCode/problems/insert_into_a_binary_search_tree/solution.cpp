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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if (val > root->val) { // Continue searching in the right subtree
            if (root->right) { // the position is occupied, continue to search
                insertIntoBST(root->right, val);
            } else { // position is empty, insert position found, put val here
                root->right = new TreeNode(val);
            }
        } else { // Continue searching in the left subtree
            if (root->left) { // the position is occupied, continue to search
                insertIntoBST(root->left, val);
                } else { // position is empty, insert position found, put val here
                root->left = new TreeNode(val);
            }
        }
        return root;
    }
};