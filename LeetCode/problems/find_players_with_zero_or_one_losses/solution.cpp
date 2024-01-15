class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        set<int> st;
        vector<vector<int>> ans(2, vector<int>{});
        
        unordered_map <int,int> count;
        
        for(int i=0;i<matches.size();i++)
        {
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);
            
            count[matches[i][1]]+=1;
        }
        
        for(auto i:st)
        {
            if(count[i]==0) ans[0].push_back(i);
            else if(count[i]==1) ans[1].push_back(i);
        }
        
        return ans;
    }
};