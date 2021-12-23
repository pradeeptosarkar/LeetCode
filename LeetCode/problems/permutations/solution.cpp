class Solution {
public:
    void getAllPossiblePermute(vector<vector<int>>& allPermute, vector<int> &nums, int idx){
        if(idx >= nums.size()){
            allPermute.push_back(nums);
        }
        
        for(int i = idx; i<nums.size(); ++i){
            if(i!=idx){ 
                swap(nums[i], nums[idx]);
            }
            
            getAllPossiblePermute(allPermute, nums, idx+1);
            
            if(i!=idx){ // restore previous array while backtracking
                swap(nums[i], nums[idx]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)return {nums};
        
        vector<vector<int>> allPermute;
        int startIndex = 0;
        
        getAllPossiblePermute(allPermute, nums, startIndex );
        
        return allPermute;
    }
};