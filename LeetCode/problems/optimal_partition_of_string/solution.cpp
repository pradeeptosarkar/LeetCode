class Solution {
public:
    int partitionString(string s) 
    {
        vector<int> pos(26);
        int ans=0, lastIdx=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(pos[s[i]-'a']>=lastIdx)
            {
                ans++;
                lastIdx=i+1;
            }
            pos[s[i]-'a']=i+1;
        }
        return ans;
    }
};