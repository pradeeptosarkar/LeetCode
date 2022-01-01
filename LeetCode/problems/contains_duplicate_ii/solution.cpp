class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>m,count;
        for(int i=0;i<nums.size();i++){
           
            count[nums[i]]++;
                
            if(count[nums[i]]>=2 && abs(m[nums[i]]-i)<=k)
                return true;
            m[nums[i]]=i;
        }
        return false;
    }
};