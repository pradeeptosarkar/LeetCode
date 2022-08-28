class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        for(int i=0;i<queries.size();i++)
        {
            int temp=upper_bound(nums.begin(),nums.end(),queries[i]) - nums.begin();
            queries[i]=temp;
        }
        return queries;
        
    }
};