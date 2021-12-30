class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> res;
        // modifying array in this loop
        for(int i=0;i<nums.size();i++)
        {
          int num = abs(nums[i])-1;
            if(nums[num] > 0)
                nums[num] *= -1;
                
        }
        // in this loop we are checking that at which index we didn't reach means it is Disappeared element
          for(int i=1;i<=nums.size();i++)
        {
              if(nums[i-1] > 0)
                  res.push_back(i);
                  
          }
       return res; 
    }
};