class Solution {
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        int minNum=nums[0],maxNum=nums[0];
        int index=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<minNum){
                index=i;
                minNum=maxNum;
            }
            maxNum=max(nums[i],maxNum);
        }
        return index+1;
    }
};