class Solution {
public:
    
    bool checkPalindrome(string s)
    {
        for(int i=0;i<s.size()/2;i++)
            if(s[i]!=s[s.size()-i-1])
                return false;
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>> ans;
        unordered_map<string,int> mp;
        
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            reverse(temp.begin(), temp.end());
            mp[temp]=i;
        }
        
        if(mp.count(""))
            for(int i=0;i<words.size();i++)
                if(words[i].size()>0 and checkPalindrome(words[i]))
                    ans.push_back({i,mp[""]});
        
        for(int i=0;i<words.size();i++)
        {
            string left, right;
            
            for(int j=0;j<words[i].size();j++)
            {
                left.push_back(words[i][j]);
                right=words[i].substr(j+1);
                
                if(mp.count(left) and i!=mp[left] and checkPalindrome(right))
                    ans.push_back({i, mp[left]});
                if(mp.count(right) and i!=mp[right] and checkPalindrome(left))
                    ans.push_back({mp[right],i});
            }
        }
        
        return ans;
    }
};