class Solution {
public:
    int hammingWeight(uint32_t n) {
        return n==0?0:1+hammingWeight(n&(n-1));
    }
};