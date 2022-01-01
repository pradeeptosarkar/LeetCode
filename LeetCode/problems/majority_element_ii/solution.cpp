class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        map<int,int> count;
        
        for(auto num: nums)
            count[num]++;
        
        int times=nums.size()/3;
        
        vector<int> res;
        
        for(auto it: count)
        {
            if(it.second>times)
                res.push_back(it.first);
            
            if(res.size()==2)
                break;
        }
        return res;
    }
};