//Pradeepto Sarkar LC34

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans{-1,-1};
        
        if(!binary_search(nums.begin(),nums.end(),target))
            return ans;
        
        int start=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int end=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        ans[0]=start;
        ans[1]=end-1;
        return ans;
    }
};