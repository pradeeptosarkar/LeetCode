/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> finalNaryTree;    
        recNaryTreeNodes(root, finalNaryTree);   
        return finalNaryTree;
    }
    
    void recNaryTreeNodes(Node* node, vector<int> & finalNaryTree){
        if(node == nullptr) return;        
        finalNaryTree.push_back(node->val);
        
        for(auto i: node->children)
        recNaryTreeNodes(i,finalNaryTree);      
    }
};