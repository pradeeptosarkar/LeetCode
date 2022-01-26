class Solution {
public: 
    vector<TreeNode*> DP[21];
    vector<TreeNode*> helper(int n)
    {
        if(n == 1)
        {
            TreeNode* temp = new TreeNode(0);
            return {temp};
        }
        if(DP[n].size() != 0)
            return DP[n];
        
        for(int i = 1; i < n; i+=2)
        {
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n - i - 1);
                for(auto j: left)
                {
                    for(auto k: right)
                    {
                        TreeNode* temp = new TreeNode(0);
                        temp -> left = j;
                        temp -> right = k;
                        DP[n].push_back(temp);
                    }
                }
        }
        return DP[n];
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};