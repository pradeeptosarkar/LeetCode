class Solution {
public:
    bool isMirror(TreeNode *r1,TreeNode *r2){
    if(r1==NULL && r2==NULL)
        return true;
    if(r1 && r2 && r1->val == r2->val){
        return isMirror(r1->left,r2->right) && isMirror(r1->right,r2->left);
    }
    return false;
}
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};