class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0, maxOr = INT_MIN;
        int limit = pow(2, nums.size());
        for(int i = 0; i < limit; i++) {
            int Or = 0;
            for(int j = 0; j < nums.size(); j++) { 
				if((i & (1 << j)) == 0) Or |= nums[j];
			}
            if(Or > maxOr) { maxOr = Or; ans = 1; } 
			else if(Or == maxOr) ans++;
        }
        return ans;
    }
};