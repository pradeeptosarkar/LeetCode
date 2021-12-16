class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        if(!n) return false;
        int hcf=nums[0];
		
        for(int i=1;i<n;i++){
            hcf=__gcd(hcf,nums[i]);
        }
		
        return hcf==1;
    }
};