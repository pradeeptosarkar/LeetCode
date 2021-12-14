class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        int a1=nums[0],a2=INT_MAX;
        for(int i=1;i<n;i++){
            if(nums[i]>a2)return true;
            if(nums[i]>a1)a2=min(a2,nums[i]);
            else a1=nums[i];
        }
        return false;
    }
};