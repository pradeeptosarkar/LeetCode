class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int> count(26,0);

        for(auto i:s)
            count[i-'a']++;
        
        sort(count.begin(),count.end());
        
        int ans=0;
        
        for(int i=24;i>=0;i--)
        {
            if(count[i]==0)
                break;
            
            if(count[i]>=count[i+1])
            {
                int temp=count[i];
                count[i]=max(0, count[i+1]-1);
                ans+=temp-count[i];
            }
        }
        return ans;                
        
    }
};