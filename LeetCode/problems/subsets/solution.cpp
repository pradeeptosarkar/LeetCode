class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        
        int n=nums.size();
        int count=pow(2,n);
        vector<vector<int>> ans;
        
        for(int i=0;i<count;i++)
        {
            vector<int> temp;
            
            for(int j=0;j<n;j++)
                if((i&(1<<j)))
                    temp.push_back(nums[j]);
                    
            ans.push_back(temp);
        }
        return ans;
    }
};