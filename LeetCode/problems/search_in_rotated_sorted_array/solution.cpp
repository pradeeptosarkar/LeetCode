//:: Pradeepto Sarkar LC33 26/02/2022 :://

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l,r,m,k=0;
        l=1,r=nums.size()-1;
        while(l<=r)
        {
            m=(l+r)/2;
            if(nums[m]<nums[0]) 
                k=m,r=m-1;
            else l=m+1;
        }
        
        if(binary_search(nums.begin(),nums.begin()+k,target))
            return (lower_bound(nums.begin(),nums.begin()+k,target)-nums.begin());
        
        if(binary_search(nums.begin()+k,nums.end(),target))
            return (lower_bound(nums.begin()+k,nums.end(),target)-(nums.begin()));
        
        return -1;
    }
};