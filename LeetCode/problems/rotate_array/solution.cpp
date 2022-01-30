class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if (k==0) return;
        if (nums.size()==0) return;
   
        int* res = new int[nums.size()];

        for (int i=0; i<nums.size(); i++){
        int newIndex = (i + k) % nums.size();
        res[newIndex] = nums[i];
        }
   
        for (int i=0; i<nums.size(); i++){
        nums[i] = res[i];
        }
    }
};