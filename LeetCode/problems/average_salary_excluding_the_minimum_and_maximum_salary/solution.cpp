class Solution {
public:
    double average(vector<int>& salary) 
    {
        int maxi=999, mini=100001;
        int sum=0,n=salary.size();
        for(int i:salary)
        {
            sum+=i;
            if(i<mini)
                mini=i;
            if(i>maxi)
                maxi=i;
        }
        return (double)(sum-mini-maxi) / (double)(n-2);       
    }
};