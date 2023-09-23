class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums2.size();
        unordered_map<int,int> mp;
        stack<int> stk;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() and stk.top()<nums2[i])
                stk.pop();
            
            if(!stk.empty())
                mp[nums2[i]]=stk.top();
            
            stk.push(nums2[i]);
        }
        
        vector<int> ans;
        
        for(auto i:nums1)
        {
            if(mp.count(i))
                ans.push_back(mp[i]);
            else
                ans.push_back(-1);
        }
        
        return ans;
    }
};