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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        TreeNode* a=p;
        TreeNode* b=q;
        
        stack<TreeNode*> stk1({a}), stk2({b});
        
        while(!stk1.empty() or !stk2.empty())
        {
            a=stk1.top();
            b=stk2.top();
            
            if(a==NULL and b==NULL)
                ;
            else if(a==NULL or b==NULL)
                return false;
            else if(a->val!=b->val)
                return false;
            
            stk1.pop();
            stk2.pop();
            
            if(a!=NULL)
            {
                stk1.push(a->left);
                stk1.push(a->right);
            }
            
            if(b!=NULL)
            {
                stk2.push(b->left);
                stk2.push(b->right);
            }
        }
        
        return true;
    }
};