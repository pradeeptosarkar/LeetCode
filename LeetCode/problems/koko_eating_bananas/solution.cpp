class Solution {
public:
    
    bool is_possible(vector<int>arr,int h,int mid)
    {     
        int count=0;//intialise no of hour
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
         count+=ceil((arr[i]*1.0)/mid);//checking time taken to eat every pile of banana
        }
        if(count<=h)
        {
            return 1;
        }
        return 0;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();
        int start=1;//minimum possible  banana
        int end=*max_element(piles.begin(),piles.end());//maximum possible banana eaten
        if(h==n)//corner case for easy computaion
        {
            return end;        
        }
        
        int ans=-1;//intialise final answer
        while(start<=end)
        {
            int mid=(start+end)/2;// finding middle element
            cout<<mid<<endl;
            if(is_possible(piles,h,mid))//checking is it possible to eat all banana if monkey eat mid banana per hour..
            {
               ans=mid;//updating
                end=mid-1;    //moving left to find more optimal answer      
            }
            else
            {   
               start=mid+1;//moving right to remove impossible cases.
            }
        }
        return ans;
        
    }
};