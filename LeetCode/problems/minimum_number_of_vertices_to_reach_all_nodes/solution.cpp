class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        unordered_set<int> check;
        
        for(auto i: edges)
            check.insert(i[1]);
        
        vector<int> ans;
        
        for(auto i=0;i<n;i++)
            if(check.find(i)==check.end())
                ans.push_back(i);
        
        return ans;        
    }
};