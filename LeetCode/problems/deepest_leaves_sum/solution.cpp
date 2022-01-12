class Solution {
public:
	pair<int,int> getSum(TreeNode* root){
        if(!root) return {0,0};
        if(!root->left && !root->right) return {1, root->val};
        auto left = getSum(root->left);
        auto right = getSum(root->right);
        if(left.first == right.first)
            return {left.first+1, left.second + right.second};
        if(left.first > right.first)
            return {left.first+1, left.second};
        return {right.first+1, right.second}; 
    }

    int deepestLeavesSum(TreeNode* root) {
        return getSum(root).second;
    }	
};