class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1) return 1;

        int first = 1, last = n;
        int count = n;
        for(int step = 1, digit = 1; first != last; step <<= 1, digit++) {
            if(digit % 2 == 1) {
                first += step;
                if(count % 2 == 1)
                    last -= step;
            } else {
                last -= step;
                if(count % 2 == 1)
                    first += step;
            }
            count /= 2;
        }
        return first;
    }
};