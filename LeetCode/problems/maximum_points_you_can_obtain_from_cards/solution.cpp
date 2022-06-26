class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int i=0, j=cardPoints.size()-k-1;
        int temp_sum=0;
        
        for(int i=0;i<=j;i++)
            temp_sum+=cardPoints[i];
        
        int tot_sum=temp_sum;
        
        for(int kk=j+1;kk<cardPoints.size();kk++)
            tot_sum+=cardPoints[kk];
        
        int ans=tot_sum-temp_sum;
        
        i++,j++;
        
        for(i,j;j<cardPoints.size();i++,j++)
        {
            temp_sum-=cardPoints[i-1];
            temp_sum+=cardPoints[j];
            ans=max(ans, tot_sum-temp_sum);
        }
        
        return ans;
        
    }
};