class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) 
    {
        int ans=0;
        int i=nums.size();
        int j=nums[0].size();
        for(int k=0;k<i;k++)
            sort(nums[k].begin(), nums[k].end());
        for(int k=j-1;k>=0;k--)
        {
            priority_queue<int> pq;
            for(int r=0;r<i;r++)
                pq.push(nums[r][k]);
            ans+=pq.top();
        }
        return ans;
        
    }
};