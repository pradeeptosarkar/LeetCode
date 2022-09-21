class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> ret;
        int sum=0;
        
        for (auto query:queries) {
            if (ret.size() == 0) {
                nums[query[1]] = query[0] + nums[query[1]];
                for (int a:nums) 
                    if (a%2 == 0) 
                        sum += a;
            }
            else {
                if (nums[query[1]] % 2 == 0) sum -= nums[query[1]];
                nums[query[1]] = query[0] + nums[query[1]];
                if (nums[query[1]] % 2 == 0) sum += nums[query[1]];                
            }
            
            ret.push_back(sum);
        }
        
        return ret;        
    }
};