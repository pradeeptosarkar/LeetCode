class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
       if (nums1.size()>nums2.size()) 
       {
            return intersect(nums2,nums1);
       }

        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> ans;
        auto it=nums2.begin();
        for (const auto& i : nums1) 
        {
            it=lower_bound(it,nums2.end(),i);
            if(it!=nums2.end() && *it==i) 
            {
              ans.emplace_back(*it++);
            }
        }
        
        return ans;  
    }
};