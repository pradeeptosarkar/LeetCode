class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, minSum = nums[0], maxSum = nums[0], curMax = 0, curMin = 0;
        for(auto &e : nums){
            total += e;
            
            curMax = max(e, curMax+e);
            maxSum = max(maxSum, curMax);
            
            curMin = min(e, curMin+e);
            minSum = min(minSum, curMin);
        }
        
        return maxSum < 0 ? maxSum : max(maxSum, total-minSum);
    }
};