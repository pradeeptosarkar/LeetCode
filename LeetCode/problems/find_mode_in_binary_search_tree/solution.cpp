class Solution {
public:
    unordered_map<int,int>mp;
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        int max=0;
        findMaxFreq(root);
        for(auto it:mp){
            if(it.second>max){
                ans={};
                ans.push_back(it.first);
                max=it.second;
            }
            else if(max==it.second){
                ans.push_back(it.first);
                max=it.second;
            }
        }
        return ans;
    }
    void findMaxFreq(TreeNode* root){
        if(root==NULL){
            return;
        }
        mp[root->val]++;
        findMaxFreq(root->left);
        findMaxFreq(root->right);
    }
};