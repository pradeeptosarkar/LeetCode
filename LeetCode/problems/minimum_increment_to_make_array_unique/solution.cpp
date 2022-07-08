class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        vector<int> count(1e5+1, 0);
    
    int res = 0;
    int maxe = 0;
    
    for(int it: nums) {
        count[it]++;
        maxe = max(maxe, it);
    }
    
    for(int i = 0; i < maxe; i++) {
        if(count[i] <= 1) continue;
        count[i+1] += count[i] - 1;
        res += count[i] - 1;
        count[i] = 1;
    }
    
    int element = maxe;
    int freq = count[maxe];
    
    res += (freq*(2 * maxe + (freq - 1) * 1)) / 2 - maxe*freq;
    return res;
    }
};