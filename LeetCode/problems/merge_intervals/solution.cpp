class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        sort(I.begin(), I.end());
        vector<vector<int>> ans {I[0]};                        // adding 1st interval to avoid checking ans.empty() each time in loop
        for(auto i : I)
            if(i[0] <= ans.back()[1])                          // merge intervals if they overlap
                ans.back()[1] = max(ans.back()[1], i[1]);
            else                                               // else insert new interval
                ans.push_back(i);
        return ans;
    }
};