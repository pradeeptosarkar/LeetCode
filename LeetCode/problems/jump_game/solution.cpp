class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), p=n-1;
        bool ans=true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=p-i){
                p=i;
                ans=true;
            }
            else{
                ans=false;
            }
        }
        
        return ans;
    }
};