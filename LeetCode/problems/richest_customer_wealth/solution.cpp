class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
       
        int ans=0;
        int temp=0;
        
        int m=accounts.size();
        int n=accounts[0].size();
        
        for(int i=0;i<m;i++)
        {
            temp=0;
            temp=accumulate(accounts[i].begin(), accounts[i].end(), temp);
            ans=max(temp,ans);
        }
        return ans;
    }
};