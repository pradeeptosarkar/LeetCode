class Solution {
public:
    int brokenCalc(int st, int t) {
        int cnt=0;
        while(1){
            if(t<st) break;
            if(t==st) break;
            if(t&1){
               cnt++;
               t+=1;
            }
            t=t/2;
            cnt++;
        }
        if(t<st) cnt+=(st-t);
        return cnt;
    }
};