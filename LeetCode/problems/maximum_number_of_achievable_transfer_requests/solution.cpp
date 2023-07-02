class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        int ans=0;
        
        for(int mask=0; mask<(1<<requests.size()); mask++)
        {
            vector<int> inDegree(n,0);
            int currPos=requests.size()-1;
            int setBits=__builtin_popcount(mask);
            
            if(setBits<=ans)
                continue;
            
            for(int curr=mask; curr>0; curr>>=1,currPos--)
            {
                if(curr & 1)
                {
                    inDegree[requests[currPos][0]]--;
                    inDegree[requests[currPos][1]]++;
                }
            }
            
            bool flag=true;
            
            for(int i=0;i<n;i++)
            {
                if(inDegree[i])
                {
                    flag=false;
                    break;
                }
            }
            
            if(flag)
                ans=setBits;
        }
        
        return ans;        
    }
};