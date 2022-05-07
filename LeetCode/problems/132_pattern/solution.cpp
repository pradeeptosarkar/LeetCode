class Solution {
public:
    int dp[200011];
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        if(n<3) return false;
        
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            dp[i] = min(dp[i-1], nums[i]);
        }
        
        set<int>myset;
        myset.insert(nums[n-1]);
        for(int i=n-2;i>0;i--){

            auto fs = myset.begin();
            auto ls = myset.end();
            ls--;
            if( (*fs) < nums[i] ){
                if( (*ls) < nums[i] ){
                    if(dp[i-1] < (*ls)){
                        return true;
                    }
                }
                else{
                    auto it = myset.lower_bound(nums[i]);
                    it--;
                    if(dp[i-1] < (*it)){
                        return true;
                    }
                }
            }
            
            myset.insert(nums[i]);
        }
        
        return false;
    }
};