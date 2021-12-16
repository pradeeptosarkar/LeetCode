class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
       long long  int l=1;
       long long  int r = x;
       long long int ans = -1;
        
        while(l<=r){
          long long   int mid = l +(r-l)/2;
            
            if(mid *mid == x){
                ans = mid;
                break;
            }
            else if(mid*mid < x){
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return ans;
    }
};