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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <vector<int>> ret;
        if(root == NULL){
            vector<double> v;
            return v;
        } 
        queue <TreeNode*> q;
        q.push(root);
        vector <int> dummy;
        dummy.push_back(root->val);
        ret.push_back(dummy);
        
        // bfs level order
        while(q.size() != 0){
            int size = q.size();
            dummy.clear();
            for(int i = 0; i < size; i++){
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    dummy.push_back(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    dummy.push_back(curr->right->val);
                }
            }
            if(dummy.size() != 0) ret.push_back(dummy);
        }
        
        // get avg for every array in 2d array
        vector <double> v;
        for(int i = 0; i < ret.size(); i++){
            double s = 0;
            for(int j = 0; j < ret[i].size(); j++)s += ret[i][j];
            
            v.push_back(s / ret[i].size());
        }
        return v;
    }
};