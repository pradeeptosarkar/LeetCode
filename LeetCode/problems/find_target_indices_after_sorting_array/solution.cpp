class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        int count=0, sum=0;
        
        for(int i:nums)
        {
            if(i==target)
                count++;
            
            else if(i<target)
                sum++;
        }
        
        vector<int>ans;
        
        while(count--)
            ans.push_back(sum++);
        
        return ans;
    }
};