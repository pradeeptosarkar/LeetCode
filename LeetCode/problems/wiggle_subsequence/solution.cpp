class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1; 
        for (int i = 1, prev = 0; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i-1]; 
            if (diff != 0) {
                if (prev * diff <= 0) ++ans; 
                prev = diff; 
            }
        }
        return ans; 
    }
};