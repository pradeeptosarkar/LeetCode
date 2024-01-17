class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        short m[2001] = {}, s[1001] = {};
  
        for (auto n : arr) 
            ++m[n + 1000];
  
        for (auto i = 0; i < 2001; ++i)
            if (m[i] && ++s[m[i]] > 1) return false;
  
        return true;
    }
};