class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<bool> used(n,0);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,k,n,used,ans,temp);
        return ans;        
    }
    
    void solve(int idx,int k,int n,vector<bool>&used,vector<vector<int>>&ans, vector<int>&temp)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<=n;i++)
        {
            if(!used[i])
            {
                used[i]=1;
                temp.push_back(i);
                solve(i+1,k,n,used,ans,temp);
                used[i]=0;
                temp.pop_back();
            }
        }
    }
};