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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        
        if(!root)
            return ans;
        
        stack<TreeNode*> stk;
        TreeNode* node = root;
        
        while(true)
        {
            if(node!=NULL)
            {
                stk.push(node);
                node=node->left;
            }
            
            else
            {
                if(stk.empty())
                    break;
                
                node=stk.top();
                ans.push_back(node->val);
                stk.pop();
                
                node=node->right;
            }
        }
        
        return ans;
    }
};