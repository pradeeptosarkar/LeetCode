class Solution {
public:
    long long minimumRemoval(vector<int>& beans) 
    {
        long long  n = beans.size();
        long long ans = LLONG_MAX;
        long long sum = 0;
        sort(beans.begin(),beans.end());
        for(long long i = 0;i<n;i++){
            sum += beans[i];
        }
        long long prev = -1;
        for(long long i = 0;i<n;i++){
            if(beans[i] != prev){
                prev = beans[i];
                long long temp =sum-(beans[i]*(n-i));
                ans = min(ans,temp);
            }
        }
                
        return ans;
        
    }
};