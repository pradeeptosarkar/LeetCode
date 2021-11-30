class Solution {
public:
    bool isNumber(string s) {
        int state[10][5] = {{0, 1, 2, -1, 4},             // begin or blank
                         {-1, -1, 2, -1, 4},           // sign before exponent
                         {-1, -1, -1, -1, 7},          // dot, no number before it
                         {-1, 9, -1, -1, 5},            // exponent
                         {8, -1, 6, 3, 4},              // number 
                         {8, -1, -1, -1, 5},           // exponent number
                         {8, -1, -1, 3, 7},            // dot with number front
                         {8, -1, -1, 3, 7},            // number with dot front
                         {8, -1, -1, -1, -1},                 // blank at end
                         {-1, -1, -1, -1, 5}          // sign after exponet
                        };
        
        int pre = 0, cur = 0, input;
        for (int i = 0; i < s.size(); i++) {
            pre = cur;
            if (s[i] == ' ')
                input = 0;
            else if (s[i] == '+' || s[i] == '-')
                input = 1;
            else if (s[i] == '.')
                input = 2;
            else if (s[i] == 'E' || s[i] == 'e')
                input = 3;
            else if (s[i] >= '0' && s[i] <= '9')
                input = 4;
            else
                input = -1;
            
            if (input == -1 || (cur=state[pre][input]) == -1)
                return false;   

        }
        
        return cur > 3 && cur < 9;
    }
};