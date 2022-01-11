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
    int result = 0;
    int depthfirstsearch(TreeNode *root) {
		//Checking if there are some child tree and if its true dfs it or else the node is leaf node therfore make it 0
        int left = (root->left ? depthfirstsearch(root->left) : 0), right = (root->right ? depthfirstsearch(root->right) : 0);
        // Finding the current tilt( |left-right| )
		result += abs(left - right);
		// returning the total sum
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        if (root) depthfirstsearch(root);
        return result;
    }
};