class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // Avoid duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Avoid duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return ans;
    }
};
