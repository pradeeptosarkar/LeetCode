//::Pradeepto Sarkar LC228:://

class Solution {
public:
   vector<string> summaryRanges(vector<int>& nums) 
{
    vector<string> res;
    
    if (nums.empty())
        return res;
    
    int i = 0;
    
    while (i < nums.size())
    {
        int bgn = i;
        
        while (i + 1 < nums.size() and nums[i + 1] == nums[i] + 1)
            i++;

        if (bgn != i)
        {
            stringstream ss;
            ss << nums[bgn] << "->" << nums[i];
            res.push_back(ss.str());
        }
        
        else 
        {
            res.push_back(std::to_string(nums[bgn]));
        }
        
        i++;
    }
    
    return res;
}
};