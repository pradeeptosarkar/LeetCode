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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Stacks to traverse trees iteratively starting from roots
        stack<TreeNode*> p_cand({p}), q_cand({q});
        
        // Create pointers to access nodes at top of stacks
        TreeNode *a, *b;
        
        // Loop while there are nodes in the stack 
        while(!p_cand.empty() && !q_cand.empty()) {
            // Get nodes from top of stack
            a = p_cand.top();
            b = q_cand.top();
            
            // If both nodes are nullptr, do nothing
            if(a == nullptr && b == nullptr)
                ;
            // If one node is nullptr and not the other, the trees are dissimilar
            else if(a == nullptr || b == nullptr)
                return false;
            // If node values are not the same, the trees are dissimilar
            else if(a->val != b->val)
                return false;

            // Pop latest node off stack
            p_cand.pop();
            q_cand.pop();

            // Push children nodes from tree as long as nodes are not nullptr
            if(a != nullptr) {
                p_cand.push(a->left);
                p_cand.push(a->right);
            }
            
            if(b != nullptr) {
                q_cand.push(b->left);
                q_cand.push(b->right);
            }
        }
        
        return true;
    }
};