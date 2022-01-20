class Solution {
public:
    int numTrees(int n) {
        long long int mul =1;
        int num = 2*n;
        for(int i=0;i<n;i++){
            mul *= (num-i);
            mul /= (i+1);
        }
        int den = (n+1);
        return mul/den;
    }
};