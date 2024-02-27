class Solution {
public:
    vector<vector<int>> getSumOfSubset(int start, int end,vector<int>& nums)
    {
        int n = end-start+1;
        vector<vector<int>> res(n+1);
        for(int i = 0; i < (1<<n); ++i)
        {
            int sum = 0;
            int len = 0;
            for(int j = 0; j < n; ++j)
            {
                if((1<<j)&i)
                {
                    sum += nums[start+j];
                    ++len;
                }
            }
            res[len].push_back(sum);

        }
        return res;
    }
    int minimumDifference(vector<int>& nums) 
    {
        int n = nums.size()/2;
        int S = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;
        vector<vector<int>> left = getSumOfSubset(0,n-1,nums);
        vector<vector<int>> right = getSumOfSubset(n,2*n-1,nums);
        for(auto& sums: right)
        {
            sort(sums.begin(),sums.end());
        }
        for(int l = 1; l <=n; ++l)
        {
            for(auto& sum:left[l])
            {
                int inf = 2*(sum+right[n-l][0])-S;
                int sup = 2*(sum+right[n-l].back())-S;
                if(sup<=0||inf>=0)
                {
                    ans = min({ans,abs(sup),abs(inf)});
                    continue;
                }
                auto it = lower_bound(right[n-l].begin(), right[n-l].end(), (S+S%2)/2-sum);
                ans = min({ans, abs(2*(sum + *it) - S), abs(2*(sum + *(--it)) - S)});

            }
        }
        
        return ans;
    }
};