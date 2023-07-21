class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        vector <int> len(nums.size(), 1);
        vector <int> count(nums.size(), 1);

        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(len[i] < len[j]+1){
                        len[i] = len[j]+1;
                        count[i] = count[j];
                    }
                    else
                    if(len[i] == len[j]+1){
                        count[i] += count[j];
                    }
                }
            }
        }

        int ans = 0, maxLen = 0;
        for(auto u : len){
            if(u > maxLen)
                maxLen = u;
        }

        for(int i = 0; i<len.size(); i++){
            if(len[i] == maxLen)
                ans += count[i];
        }
        return ans;
    }
};