class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high){
        // Reach desirable node (node whose value lies between low and high)
        while(root && (root->val<low || root->val>high)){
            root = root->val<low ? root->right : root->left;
        }
        
        // If current node==NULL then we couldn't find any desirable node
        if(root != NULL){
            // but if it wasn't then right now I am standing on a desirable node 
			// so I need to fix the left and right sub-tree of our current node.
			// And do it in a recursive fashion so that things get fixed for every node.
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right,low,high);            
        }
        
        // At this point, I have reached the desirable and also fixed it's left and right sub-tree recursively so return the current node.
        return root;
    }
};