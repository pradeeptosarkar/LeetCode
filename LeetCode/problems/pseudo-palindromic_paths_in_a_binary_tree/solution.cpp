class Solution {
    int cnt = 0;
    int path = 0;
public:
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        const int xor_val = (1 << node->val);
        path ^= xor_val;
        if (node->left == nullptr && node->right == nullptr) {
            if ((path & (path - 1)) == 0)
                cnt += 1;
        }
        
        dfs(node->left);
        dfs(node->right);

        path ^= xor_val;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};