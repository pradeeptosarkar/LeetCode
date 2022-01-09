class Solution {
public:
    int numSplits(string s) {
        int goodSplits = 0;
        int n = s.size();
        unordered_map<char, int> left, right;
        
        ++left[s[0]];
        for(int i = 1; i < n; ++i)
            ++right[s[i]];
        
        for(int i = 1; i < n; ++i)
        {
            if(left.size() == right.size())
                ++goodSplits;
            
            ++left[s[i]];
            --right[s[i]];
            if(right[s[i]] == 0)
                right.erase(s[i]);
        }
              
        return goodSplits;
    }
};