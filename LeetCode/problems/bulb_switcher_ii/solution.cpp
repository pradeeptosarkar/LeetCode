class Solution {
public:
    int flipLights(int n, int p) 
    {
    return !p or !n ? 1: n>3 ? flipLights(3, p): flipLights(n-1, p-1) + flipLights(n-1, p);
    }
};