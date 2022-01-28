/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==nullptr)
            return nullptr;
        helper(root->left,root->right,root->left,root->right);
        return root;
        
    }
    
    void helper(Node* l, Node* r, Node* l2, Node* r2)
    {
        if(l&&r)
        {
            l->next=r;
            helper(l->left,l->right,l->left,l->right);
            helper(r->left,r->right,r->left,r->right);
        }
        if(l2&&r2)
        {
            l2->next=r2;
            helper(nullptr,nullptr,l2->right,r2->left);
        }
    }
};