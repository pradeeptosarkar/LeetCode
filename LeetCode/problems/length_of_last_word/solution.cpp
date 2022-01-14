class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int cnt = 0;
        while (i >= 0){
            if(s[i] == ' '){
                if(cnt != 0)
                    break;
            }
            else
                cnt++;
            i--;
        }
        return cnt;
    }
};