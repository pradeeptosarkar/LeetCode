class Solution {

public:

    int maxAncestorDiff(TreeNode* root, int maxi=INT_MIN, int mini=INT_MAX) {

        if(!root) return(maxi-mini);

        maxi=max(maxi, root->val);

        mini=min(mini, root->val);

        return max(maxAncestorDiff(root->left, maxi, mini), maxAncestorDiff(root->right, maxi, mini));

    }

};