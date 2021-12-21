class Solution {
public:
    int totalHammingDistance(vector<int>& A) {
       int ans = 0;
    int N=A.size();
    for(int j=0; j<32; j++)
    {
        int n = 0, m=0;
        for(int i=0; i<N; i++)
        {
            if(A[i]&(1<<j))
                n++;
            else
                m++;
        }
        ans += n*m;
    }
    return ans;
    }
};