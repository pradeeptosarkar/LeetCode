class Solution {
public:
    int bulbSwitch(int n) 
    {
        if (n == 0) 
            return 0;
        long long it = 1;
        long long counter = 1;
        long long additioner = 3;
        while (it <= n) {
            it += additioner;
            additioner += 2;
            if (it <= n) counter++;
        }
        return counter; 
    }
};