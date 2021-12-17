class Solution {
public:
    int findNthDigit(int n) 
    {
         long long i = 1, base = 1;
        while (n > i * base * 9) {
            n -= i * base * 9;
            ++i, base *= 10;
        }

        return (n % i == 0) ? 
            to_string(n / i + base - 1).back() - '0' : 
            to_string(n / i + base)[n % i - 1] - '0';
    }
};