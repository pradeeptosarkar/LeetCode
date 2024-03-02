class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int i = nums.size()-1;
        vector<int>v(nums.size(),0);                   
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                v[i] = nums[l]*nums[l];                    
                l++;
            }else{
                v[i] = nums[r]*nums[r];
                r--;
            }
            i--;
        }
        return v;        
    }
};
