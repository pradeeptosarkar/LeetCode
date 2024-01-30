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

class BSTIterator
{
    stack<TreeNode *> stk;
    
    bool reverse=true;
    
    public:
    
    BSTIterator(TreeNode *root, bool isRev)
    {
        reverse=isRev;
        pushAll(root);
    }
    
    bool hasNext()
    {
        return !stk.empty();
    }
    
    int next()
    {
        TreeNode *temp=stk.top();
        stk.pop();
        
        if(!reverse) 
            pushAll(temp->right);
        else
            pushAll(temp->left);
        
        return temp->val;
    }
    
    private:
    
    void pushAll(TreeNode *node)
    {
        for(;node!=NULL;)
        {
            stk.push(node);
            if(reverse)
                node=node->right;
            else
                node=node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        if(!root)
            return false;
        
        BSTIterator left(root, false);
        BSTIterator right(root, true);
        
        int i=left.next();
        int j=right.next();
        
        while(i<j)
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i=left.next();
            else
                j=right.next();
        }
        
        return false;
    }
};