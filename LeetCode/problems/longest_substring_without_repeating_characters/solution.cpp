class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size()<=1)
            return s.size();
        
        map<char, int> mp;
        int ans=INT_MIN, curr=0;
        
        for(int i=0;i<s.size();i++)
        {
            ans=max(ans, i-curr);
            
            if(mp.find(s[i])!=mp.end() and mp[s[i]]>=curr)
                curr=mp[s[i]]+1;
            
            mp[s[i]]=i;
        }
        
        return (ans<s.size()-curr)? s.size()-curr: ans;
        
    }
};