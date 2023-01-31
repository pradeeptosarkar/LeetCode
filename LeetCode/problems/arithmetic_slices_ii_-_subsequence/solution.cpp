class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n = nums.size();
        long long int ans = 0;
        vector<map<long long int, int>> cnt(n);
        
        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                long long delta = (long long)nums[i] - (long long)nums[j];
                int sum = 0;
                if (cnt[j].find(delta) != cnt[j].end()) 
                    sum = cnt[j][delta];
                
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        }
        return (int)ans;
    }
};