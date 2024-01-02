class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<int> count(nums.size()+1,0);
        vector<vector<int>> ans;    
        
        for(int i:nums)
        {
            if(count[i]>=ans.size())
                ans.push_back({});
            
            ans[count[i]++].push_back(i);
        }
            
        return ans;
    }
};