class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        if(hour<=dist.size()-1)
            return -1;
        
        int left=1, right=1e7;
        
        while(left<right)
        {
            int mid= (left+right)/2;
            int temp=0;
            
            for(int i=0;i<dist.size()-1;i++)
                temp+= dist[i]/mid + (dist[i]%mid ? 1:0);
            
            if((double)dist.back()/mid+temp<=hour)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};