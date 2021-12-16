class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
      int n = nums.size();
        int i = 0;
        int j = 1;
        int k = 0;
        while(j<n)
        {
            if(nums[i]==val && nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
                j++;
                
            }
            else if(nums[i]==val && nums[j]==val){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(nums[i]!=val)
                k++;
        }
        return k;
    }
};