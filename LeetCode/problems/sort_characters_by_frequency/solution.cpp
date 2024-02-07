class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> mp;
        
        for(int i:s)
            mp[i]++;
        
        vector<vector<char>> bucket(s.length()+1);
        
        for(auto [ch,freq]:mp)
            bucket[freq].push_back(ch);
        
        string ans="";
        
        for(int i=s.length();i>=1;i--)
        {
            for(auto ch:bucket[i])
                ans.append(i,ch);
        }
        
        return ans;
    }
};