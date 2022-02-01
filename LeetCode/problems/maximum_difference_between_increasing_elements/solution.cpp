class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int n = nums.size(), res = 0;
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] < nums[j])
                    res = max(res, nums[j] - nums[i]);
        
        return res > 0 ? res : -1;
    }
};