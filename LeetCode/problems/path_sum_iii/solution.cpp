class Solution {
public:
    int target;
    unordered_map<int, int> prefix;
    int ret = 0;
    int pathSum(TreeNode* root, int targetSum) 
    {
        target = targetSum;
        preorder(root, 0);
        return ret;
    }
    
    void preorder(TreeNode *node, int cur)
    {
        if (node == nullptr) return;
        cur += node->val;
        ret += (cur == target) + (prefix.find(cur - target) != prefix.end() ? prefix[cur - target] : 0);
        
        prefix[cur]++;
        preorder(node->left, cur);
        preorder(node->right, cur);
        prefix[cur]--;
        
    }
};