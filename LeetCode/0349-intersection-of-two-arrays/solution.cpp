class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> ansSet;
        vector<int> ans;
        unordered_set<int> temp;
        
        for(auto &i:nums1)
            temp.insert(i);
        
        for(auto &i:nums2)
            if(temp.find(i)!=temp.end())
                ansSet.insert(i);
        
        for(auto &i:ansSet)
            ans.push_back(i);
        
        return ans;
    }
};
