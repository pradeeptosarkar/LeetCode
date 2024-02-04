class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int> mp;
        
        for(auto i:t)
            mp[i]+=1;
        
        int i=0, j=0, ansStart=0, ansLen=INT_MAX, count=t.length(), n=s.length();
        
        while(j<n)
        {
            if(mp[s[j]]>0)
                count-=1;
            mp[s[j]]-=1;
            
            while(count==0)
            {
                if(j-i+1<ansLen)
                {
                    ansStart=i;
                    ansLen=j-i+1;
                }
                
                mp[s[i]]+=1;
                
                if(mp[s[i]]>0)
                    count+=1;
                
                i+=1;
            }
            
            j+=1;
        }
        
        return (ansLen!=INT_MAX ? s.substr(ansStart,ansLen) : "");
    }
};