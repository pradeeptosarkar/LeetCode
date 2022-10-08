class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int ans=INT_MIN;
        int i,j,k;
        int minDiff, tempDiff, tempSum;
        sort(nums.begin(), nums.end());
        
        for(i=0;i<nums.size()-2;i++)
        {
            j=i+1;
            k=nums.size()-1;
            if(i==0)
            {
                ans=nums[i]+nums[j]+nums[k];
                minDiff=abs(target-ans);
            }
            
            while(j<k)
            {
                tempSum=nums[i]+nums[j]+nums[k];
                tempDiff=abs(target-tempSum);
                
                if(tempSum==target)
                    return tempSum;
                else if(tempSum>target)
                    k--;
                else if(tempSum<target)
                    j++;
                
                if(tempDiff<minDiff)
                {
                    minDiff=tempDiff;
                    ans=tempSum;
                }
            }
        }
        
        return ans;
    }
};