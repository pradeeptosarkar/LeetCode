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
   int depth =0;
void solve(Node*root, int level)
{
    if(root==NULL) return ;
    if(root->children.size()==0){
        depth=max(depth,level);
    }
   vector<Node*> child = root->children;
    for(int i =0 ; i < child.size();i++)
    {
        solve(child[i],level+1);
    }
  
}
int maxDepth(Node* root) {
    if(root==NULL) return 0;
    solve(root,1);
    return depth ;
}
};