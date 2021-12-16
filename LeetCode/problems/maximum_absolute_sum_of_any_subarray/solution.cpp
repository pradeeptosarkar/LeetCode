class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int n=a.size();
        int cmax=a[0],cmin=a[0],res=abs(a[0]);
        for(int i=1;i<n;i++)
        {
            int prev_max=cmax,pre_min=cmin;
            cmax=max({a[i],prev_max+a[i],pre_min+a[i]});
            cmin=min({a[i],prev_max+a[i],pre_min+a[i]}); 
            res=max({res,abs(cmax),abs(cmin)});
        }
        return res;
    }
};