class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if(h==piles.size())
            return *max_element(piles.begin(), piles.end());
        
        int left=0, right=INT_MAX;
        
        while(left+1<right)
        {
            int m=(left+right)/2;
            int temp=0;
            
            for(int i=0;i<piles.size();i++)
            {
                temp+=(piles[i]/m + (piles[i]%m!=0));
                if(temp>h)
                    break;
            }
            if(temp<=h)
                right=m;
            else
                left=m;
        }
        return right;
    }
};