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
    int maxAncestorDiff(TreeNode* root, int curMin = INT_MAX, int curMax = INT_MIN) 
    {
        if(!root) 
            return curMax - curMin;
        
        curMin = min(curMin, root -> val);
        curMax = max(curMax, root -> val);
        
        return max(maxAncestorDiff(root -> left,  curMin, curMax), 
                   maxAncestorDiff(root -> right, curMin, curMax));
    }
};