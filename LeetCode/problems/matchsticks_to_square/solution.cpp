class Solution {
public:
    
    bool solve(vector<int>&matchsticks, int target, vector<int>&ans, int id)
    {
        if(id==matchsticks.size())
            return(ans[0]==ans[1] and ans[1]==ans[2] and ans[2]==ans[3]);
        
        for(int i=0;i<4;i++)
        {
            if(ans[i]+matchsticks[id]>target)
                continue;
            
            int j=i-1;
            
            while(j>=0)
            {
                if(ans[i]==ans[j])
                    break;
                j--;
            }
            
            if(j!=-1)
                continue;
            
            ans[i]+=matchsticks[id];
            if(solve(matchsticks,target,ans,id+1))
                return true;
            
            ans[i]-=matchsticks[id];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) 
    {
        if(matchsticks.size()==0)
            return false;
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) 
            return false;
        int target=sum/4;
        vector<int> ans(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return solve(matchsticks,target,ans,0);
        
    }
};