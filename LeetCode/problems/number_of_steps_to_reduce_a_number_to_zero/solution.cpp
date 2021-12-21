class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while(num != 0)
        {
            if((num & 1) == 0 ) // equivalent to num % 2
			{
			num >>= 1; // num = num >> 1 => num /= 2
			}
            else num -= 1;
            cnt++;
        }
        return cnt;
    }
};