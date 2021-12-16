class Solution {
public:
    int xorOperation(int n, int start) 
    {
        return (n == 0) ? 0 : (start + 2 * (n - 1)) ^ xorOperation(n - 1, start);
    }
};