class Solution {
public:
    string longestPalindrome(string s) {
        const int len = 2*s.length()+1;
        int P[len];
        int center=0, right=0, maxlen=0;
        string ret="";
        for (int i=0; i<len; i++) {
            P[i] = 0;
            if (i<right) {
                P[i] = std::min(right-i, P[2*center-i]);
            }
            int a=i-P[i]-1, b=i+P[i]+1;
            while (a>-1 and b<len) {
                if (a%2==0 or s[a/2]==s[b/2]) {
                    a--;
                    b++;
                    P[i]++;
                } else {
                    break;
                }
            }
            if (i+P[i]>right) {
                right = i+P[i];
                center = i;
                if (maxlen<P[i]) {
                    maxlen=P[i];
                    if ((i-P[i])%2 == 0) {
                        ret = s.substr((i-P[i])/2, (i+P[i])/2-(i-P[i])/2);
                    } else {
                        ret = s.substr((i-1-P[i])/2, (i-1+P[i])/2-(i-1-P[i])/2);
                    }
                }
            }
        }
        return ret;
    }
};