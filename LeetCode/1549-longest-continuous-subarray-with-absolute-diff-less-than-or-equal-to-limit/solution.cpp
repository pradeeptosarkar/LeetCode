class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        multiset<int> m;
     int st = 0 , ans = 0;
     for(int i=0;i<nums.size();i++){
         m.insert(nums[i]);
         auto it = (--m.end());
         auto it2 = m.begin();
         while(*it - *it2 > limit){
             m.erase( m.find(nums[st++]));
             it2 = m.begin();
             it = (--m.end());
         }
         ans = max(ans , i - st + 1);
     }
    return ans;
    }
};
