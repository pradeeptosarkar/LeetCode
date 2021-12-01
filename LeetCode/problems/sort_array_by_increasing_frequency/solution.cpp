class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int,int> cnt;
        for(auto num:nums){
            cnt[num]++;
        }
        
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return cnt[a] == cnt[b] ? a>b:cnt[a]<cnt[b];
        });
        
        return nums;
    }
};