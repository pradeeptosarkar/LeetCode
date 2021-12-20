class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        std::queue<Node*> curr_Q;
        std::queue<Node*> nxt_Q;
        curr_Q.push(root);
        while(!curr_Q.empty()){
            Node* n = curr_Q.front();
            curr_Q.pop();
            if(n->left != nullptr){
                nxt_Q.push(n->left);
                nxt_Q.push(n->right);
            }
            if(curr_Q.size() == 0){
                n->next = nullptr;
                std::swap(curr_Q, nxt_Q);
            }
            else
                n->next = curr_Q.front();
        }
        return root;
    }
};