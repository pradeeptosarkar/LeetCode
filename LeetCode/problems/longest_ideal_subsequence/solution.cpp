class Solution {
public:
    int longestIdealString(string s, int k) 
    {
        unordered_map<char,int>mp;
        int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            int longest=0;
            char curr=s[i];
            for(int j=0;j<=k;j++)
            {
                char prev=char(curr-j);
                char succ=char(curr+j);
                
                if(mp.count(prev))
                    longest=max(longest,mp[prev]);
                if(mp.count(succ))
                    longest=max(longest,mp[succ]);
            }
            mp[curr]=longest+1;
            ans=max(ans,longest+1);
        }
        return ans;
    }
};