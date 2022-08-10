class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) 
    {
        vector<long long> candiesCountL = {candiesCount[0]};
        for (int i = 1; i < candiesCount.size(); i++)
            candiesCountL.emplace_back(candiesCountL[i - 1] + candiesCount[i]);    
        vector<bool> ans;
        for(auto & query : queries) {
            long long lo = query[1], hi = query[2] * (long long)(query[1] + 1);
            if(query[0] == 0) ans.emplace_back(candiesCountL[query[0]] > lo);
            else if((candiesCountL[query[0] - 1] <= lo && candiesCountL[query[0]] > lo) ||
                    (candiesCountL[query[0] - 1] > lo && candiesCountL[query[0] - 1] < hi))
                 ans.emplace_back(true);
            else ans.emplace_back(false);
        }
        return ans;
        
    }
};