class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int> ans;
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int s=0;
        
        for(int i = 0;i<n;i++)
            s = s + nums[i];
        
        int duplicate = 0;
        for(int i = 0;i<n;i++)
        {
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            
            else
            {
                duplicate = abs(nums[i]);
                break;
            }
        }
        s = s - duplicate;
        int missed = sum - s;
        ans.push_back(duplicate);
        ans.push_back(missed);
        return ans;
        
    }
};