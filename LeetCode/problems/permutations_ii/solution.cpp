class Solution {
public:
    map<int,int> mp;
    vector<vector<int>> answers;
    int n;
    void rec(vector<int> &ans)
    {
        
        if(ans.size()==n)
        {
            answers.push_back(ans);
            return ;
        }
        
        for(auto &x: mp)
        {
            if(x.second!=0)
            {
                ans.push_back(x.first);
                x.second-=1;
                rec(ans);
                ans.pop_back();
                x.second+=1;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // unique permutations 
        for(auto x:nums)mp[x]++;
        vector<int> ans;
        n=nums.size();
        rec(ans);
        return answers;
    }
};