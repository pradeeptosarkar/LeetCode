class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums[0],e=nums[0];
        do
        {
            s=nums[s];
            e=nums[nums[e]];
        }while(s!=e);
        e=nums[0];
        while(e!=s)
            e=nums[e],s=nums[s];
        return e;
    }
};