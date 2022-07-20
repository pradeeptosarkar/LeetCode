class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        unordered_map<char,vector<int>> mp;
        int i=0;
        for(auto it:s)
        {
            mp[it].push_back(i);
            i++;
        }
        
        int ans=0;
        
        for(auto w:words)
        {
            int last=-1;
            int j=0;
            
            for(auto it:w)
            {
                auto ptr=upper_bound(mp[it].begin(), mp[it].end(), last);
                
                if(ptr==mp[it].end())
                    break;
                
                last=*ptr;
                
                if(j==w.size()-1)
                    ans+=1;
            
                j++;
            }
            
        }
        return ans;
        
    }
};