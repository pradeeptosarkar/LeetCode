class Solution {
    
public:
    
    // binary search
    bool isPerfectSquare(int num) {      
        long min = 0, max = num;
        while(min <= max) {
            long mid = (min + max) / 2;
            if(mid * mid == num)
                return true;
            else if(mid * mid > num)
                max = mid - 1;
            else 
                min = mid + 1;
        }
        return false;
    }

    void backtrack(vector<int>& nums, int& count, map<vector<int>, bool>& dp, vector<int> acc, int n) {
        
        // if we reached this part, we're done with a valid solution
        if(acc.size() == n) count++;

        // keep track of iterator in order to insert in constant time (iterator as 'hint')
        vector<int>::iterator it = nums.begin();
        for(int i = 0; i < nums.size(); ++i, ++it) {

            if(acc.empty() or isPerfectSquare(acc[acc.size() - 1] + nums[i])) {
                
                int val = nums[i];
                acc.push_back(nums[i]);
                
                // we keep on backtracking only if we haven't already started with such an acc
                if(dp.find(acc) == dp.end()) {
                    dp[acc] = true;
                    it = nums.erase(it);
                    backtrack(nums, count, dp, acc, n);
                    nums.insert(it, val);
                }
                acc.pop_back();
            } 
        }
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        
        int n = nums.size();
        
        map<vector<int>, bool> dp;
        
        int count = 0;
        backtrack(nums, count, dp, vector<int>(), n);
        
        return count;
    }  
};