class Solution {
public:
    int partitionString(string s) 
    {
        int ans=0;
        int latest=0;
        unordered_map<int,int> mp(26);
        
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]-'a']>=latest)
                ans++, latest=i+1;
            mp[s[i]-'a']=i+1;
        }
        return ans;
    }
};