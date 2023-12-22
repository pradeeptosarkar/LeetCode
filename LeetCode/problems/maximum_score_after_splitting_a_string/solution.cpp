class Solution {
public:
    int maxScore(string s) 
    {
        int ones=count(s.begin(), s.end(), '1');
        int ans=0;
        int zeroes=0;
        
        for(int i=0;i<s.size()-1;i++)
        {
            (s[i]=='1')?ones--:zeroes++;
            
            ans=max(ans, ones+zeroes);
        }
        
        return ans;
    }
};