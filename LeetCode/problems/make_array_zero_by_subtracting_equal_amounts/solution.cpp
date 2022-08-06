class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        set<int> sett;
        for(auto i:nums)
            if(i>0)
                sett.insert(i);
        return sett.size();
        
    }
};