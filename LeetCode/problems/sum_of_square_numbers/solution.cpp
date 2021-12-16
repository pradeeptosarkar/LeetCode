class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=0;
        long long right=sqrt(c);
        while(left<=right){            
            long long ans=(left * left)+(right * right);
            if(ans==c) return true;
            if(ans>c) right--;
            if(ans<c) left++;
        }
        return false;
    }
};