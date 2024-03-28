class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size(); 
        unordered_map<int, int> frequency; 
        
        int ans = 0;
        int charCount = 0;
        
        for (int end = 0; end < n; end++) 
        {
            frequency[nums[end]]++;
            
            if (frequency[nums[end]] == k + 1) 
                charCount++;
            
            if (charCount > 0) 
            {
                frequency[nums[ans]]--;
                
                if (frequency[nums[ans]] == k) 
                    charCount--;
                
                ans++;
            }
        }
        
        return n - ans;
    }
};
