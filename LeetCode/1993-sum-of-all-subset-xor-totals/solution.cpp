class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        
        for (int num : nums)
            ans |= num;
        
        return ans << (nums.size() - 1);
    }
};
