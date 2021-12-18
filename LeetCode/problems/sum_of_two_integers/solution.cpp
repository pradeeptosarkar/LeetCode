class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int diff = a^b, carry = (unsigned)(a&b) << 1; 
            a = diff; 
            b = carry; 
        }
        return a; 
    }
};