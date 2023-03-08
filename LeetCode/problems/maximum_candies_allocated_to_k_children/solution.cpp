class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int left=0, right=1e7;
        
        while(left<right)
        {
            int mid=(left+right+1)/2;
            
            long temp=0;
            
            for(int i=0;i<candies.size();i++)
            {
                temp+=candies[i]/mid;
                if(temp>k)
                    break;
            }
            if(temp<k)
                right=mid-1;
            else
                left=mid;
        }
        return left;
    }
};