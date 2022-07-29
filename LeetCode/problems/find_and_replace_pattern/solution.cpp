class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        int n=words[0].size();
        
        for(auto i:words)
        {
            int c=0;
            unordered_map<char,char> mp1, mp2;
            bool check=true;
            
            for(auto j:i)
            {
                if(mp1.find(pattern[c])==mp1.end() and mp2.find(j)==mp2.end())
                    mp1[pattern[c]]=j, mp2[j]=pattern[c];
                
                else
                    if(mp1[pattern[c]]!=j or mp2[j]!=pattern[c])
                        check=false;
                
                c++;
            }
            if(check)
                ans.push_back(i);    
        }
        return ans;
    }
};