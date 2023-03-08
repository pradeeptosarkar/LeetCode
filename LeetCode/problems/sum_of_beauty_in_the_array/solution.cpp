class Solution {
public:
    int sumOfBeauties(vector<int>& nums) 
    {
        int res = 0, maxj = nums[0], mink = nums.back();
    vector<bool> b2(nums.size());
    for (int i = 1; i < nums.size() - 1; maxj = max(maxj, nums[i++])) {
        b2[i] = maxj < nums[i];
        res += nums[i - 1] < nums[i] && nums[i] < nums[i + 1];
    }
    for (int i = nums.size() - 2; i > 0; mink = min(mink, nums[i--]))
        res += b2[i] && nums[i] < mink;
    return res;
    }
};