class Solution {
    vector<vector<int>> result;
    void solution(int idx, vector<int> &nums, vector<int> &temp)
    {
        if(idx == nums.size())
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solution(idx+1,nums,temp);
        temp.pop_back();
        solution(idx+1,nums,temp);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp({});
        solution(0,nums,temp);
        return result;
    }
};