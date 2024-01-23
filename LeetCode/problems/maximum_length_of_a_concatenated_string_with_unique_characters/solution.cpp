class Solution {
public:
    
    bool check(string s)
    {
        if(s.length()>26)
            return false;
        
        vector<int> freq(26,0);
        
        for(auto i:s)
        {
            freq[i-'a']+=1;
            
            if(freq[i-'a']>1)
                return false;
        }
        
        return true;
    }
    
    int maxLength(vector<string>& arr) 
    {
        int ans=0;
        vector<string> ansList;
        
        ansList.push_back("");
        
        for(auto i:arr)
        {
            if(!check(i))
                continue;
            
            vector<string> tempList;
            
            for(auto s:ansList)
            {
                string temp=s+i;
                
                if(check(temp))
                {
                    tempList.push_back(temp);
                    ans=max(ans, static_cast<int>(temp.size()));
                }
            }
            
            ansList.insert(ansList.end(), tempList.begin(), tempList.end());
        }
        
        return ans;
    }
};