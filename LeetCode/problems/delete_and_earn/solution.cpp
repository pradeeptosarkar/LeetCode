//::Pradeepto Sarkar LC740 05/03/2022:://

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_elem= *max_element(nums.begin(), nums.end());
        int dp[20001];
        vector<int> freq(20001);
        
        for(int i:nums)
            freq[i]++;
        
        dp[1]=freq[1];
        dp[2]=max(dp[1], freq[2]*2);
        
        for(int i=3;i<=max_elem;i++)
            dp[i]=max(dp[i-1], dp[i-2]+freq[i]*i);
        
        return dp[max_elem];
    }
};