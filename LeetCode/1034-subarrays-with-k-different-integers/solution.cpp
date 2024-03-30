class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        vector<int> distinctCount(nums.size() + 1, 0);

        int totalCount = 0;
        int left = 0;
        int right = 0;
        int currCount = 0;

        while (right < nums.size()) 
        {
            if (++distinctCount[nums[right++]] == 1) 
                k--;
            
            if (k < 0) 
            {
                --distinctCount[nums[left++]];
                k++;
                currCount = 0;
            }

            if (k == 0) 
            {
                while (distinctCount[nums[left]] > 1) 
                {
                    --distinctCount[nums[left++]];
                    currCount++;
                }
                
                totalCount += (currCount + 1);
            }
        }
        
        return totalCount;
    }
};
