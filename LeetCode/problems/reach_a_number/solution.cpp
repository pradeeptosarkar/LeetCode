class Solution {
public:
    int reachNumber(int target) {
        if(target < 0) target*=-1;
        long long lo = 0, hi = 1e6;
        auto is_valid = [&](int mid)->bool{
            long long lim = 1ll * mid * (mid + 1) / 2;
            return lim >= target;
        };
        while(hi - lo > 1){
            int mid = (lo + (hi - lo) / 2);
            if(is_valid(mid)) hi = mid;
            else lo = mid;
        }
        if(is_valid(lo)){
            long long val = lo * (lo + 1) / 2;
            while(abs(lo * (lo + 1) / 2 - target) & 1) lo++;
            return lo;
        }
        long long val = hi * (hi + 1) / 2;
        while(abs(hi * (hi + 1) / 2 - target) & 1) hi++;
        return hi;
    }
};