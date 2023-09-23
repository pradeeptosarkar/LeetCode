class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        stack<int> stk;
        int n=nums.size();
        vector<int> ans(n,-1);
        
        for(int i=(2*n-1); i>=0; i--)
        {
            while(!stk.empty() and nums[i%n]>=stk.top())
                stk.pop();
            
            if(i<n and !stk.empty())
                ans[i]=stk.top();
            
            stk.push(nums[i%n]);
        }
        
        return ans;
    }
};