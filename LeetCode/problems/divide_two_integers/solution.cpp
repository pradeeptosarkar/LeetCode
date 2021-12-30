class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long p = abs(dividend), q = abs(divisor);
        int sign = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ? -1 : 1;
        long long ans = 0, total = 0;
        while(true) {
            int n = 0;
            long long tmp = q;
            while(tmp + total <= p) {
                n++;
                tmp <<= 1LL;
            }
            if(n < 1) {
                break;
            }
            ans += pow(2,n-1);
            total += tmp >> 1LL;
        }
        return ans * sign;
    }
};