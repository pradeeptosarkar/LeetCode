//::Pradeepto Sarkar LC2187:://

class Solution {
public:
    
    unsigned long long count(vector<int>& time, long long mid)
    {
        unsigned long long cnt=0;
        for(auto i:time)
            cnt+=(mid/i);
        return cnt;
        
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        sort(time.begin(), time.end());
        unsigned long long left=0, right=10e14, ans=right;
        while(left<right)
        {
            unsigned long long mid=(left+right)/2;
            if(count(time, mid)>=totalTrips)
                ans=min(ans,mid), right=mid;
            else
                left=mid+1;
        }
        return ans;
    }
};