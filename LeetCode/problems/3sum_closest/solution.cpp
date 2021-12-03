class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort (nums.begin(), nums.end());
        int i,j,k;
        int minDiff;
        int sum;
        int finalSum;
        int diff;
        
        for (i=0; i<nums.size()-2; i++) {
            
            j=i+1;
            k=nums.size()-1;
            if (i==0) {
                
                finalSum=nums[i]+nums[j]+nums[k];
                minDiff=abs(target-finalSum);
            }
            while (j<k) {
                sum=nums[i]+nums[j]+nums[k];
                diff = abs(target-sum);
                if (sum==target) return sum;
                else if (sum > target) {     
                    k--;                             
                } else if (sum < target) {
                    j++;
                } else if (target == sum ) {
                    return sum;
                }
                if (diff<minDiff) { minDiff=diff; finalSum=sum;}
            }
        }

        return finalSum;
    }
};