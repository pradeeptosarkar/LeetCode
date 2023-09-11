class Solution {
public:
    
    void solve(int index, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums)
    {
        ans.push_back(temp);
        
        for(int i=index; i<nums.size(); i++)
        {
            if(i!=index and nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            solve(i+1, temp, ans, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, temp, ans, nums);
        return ans;
    }
};