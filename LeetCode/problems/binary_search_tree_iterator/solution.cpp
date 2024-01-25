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
class BSTIterator {
    
    stack<TreeNode *> myStack;
    
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() 
    {
        TreeNode* temp=myStack.top();
        myStack.pop();
        push(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
    
    private:

void push(TreeNode *node)
{
    for(;node!=NULL;myStack.push(node),node=node->left);
}
};



/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */