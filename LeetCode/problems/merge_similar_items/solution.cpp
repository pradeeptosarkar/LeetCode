class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        vector<vector<int>> ans;
        map<int,int> mp;
        for(auto i:items1)
            mp[i[0]]+=i[1];
        for(auto i:items2)
            mp[i[0]]+=i[1];
        for(auto i:mp)
            ans.push_back({i.first, i.second});
        return ans;
        
    }
};