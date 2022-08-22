class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int ans=0;
        int cost=1;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='0' or cost<=k)
            {k-=cost*(s[i]-'0'); ans++;}
            
            if(cost<=k)
                cost*=2;
        }
        
        return ans;
    }
};