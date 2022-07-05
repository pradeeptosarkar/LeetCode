class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) 
    {
        if(cost1<cost2)
            swap(cost1,cost2);
        
        long long int ans=0;
        
        if((cost1>total and cost2>total))
            return 1;
        
        
        long long int n=total/cost1;
        
        for(long long int i=0;i<=n;i++)
        {ans+= (total-(i*cost1))/cost2; ans++;}
        
        return ans;
        
    }
};