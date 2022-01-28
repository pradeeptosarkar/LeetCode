class Solution {
public:
    Node* connect(Node* root) {
        //M2: pre-order dfs, with right recursion first.
        traverse(root);
        return root;
    }

private:
    void traverse(Node* root) {
        if (!root) return;
        
        //connect me
        if (root->left) root->left->next = root->right;
        
        //connect me to next. i.e. pre to after
        Node* pre = root->left ? root->left : root->right;
        
        if (pre) {
            Node* tmp = root;
			//find the first 'next' node, which has 'after' node to connect to
            while (tmp->next) {
                Node* after = tmp->next->left ? tmp->next->left : tmp->next->right;
                if (after) {
                    if (pre->next) pre->next->next = after;
                    else pre->next = after;
                    break;
                }
                tmp = tmp->next;
            }   
        }
        
        //need to fill the next from right to left, then we can do bottom up(dfs)
        traverse(root->right);
        traverse(root->left);
    }
};