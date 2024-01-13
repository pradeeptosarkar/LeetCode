class Solution {
public:
    int minSteps(string s, string t) 
    {
        vector<int> count(26,0);
        int ans=0;
        
        for(auto c:s)
            count[c-'a']-=1;
        for(auto c:t)
            count[c-'a']+=1;
        
        for(auto i:count)
            if(i>0)
                ans+=i;
        
        return ans;
    }
};