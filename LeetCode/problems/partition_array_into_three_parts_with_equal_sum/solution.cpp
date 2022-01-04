class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
     int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];    
        }
        if(sum%3!=0)
        {
            return false;
        }
        int targetSum=sum/3;
        int currSum=0;
        for(int i=0;i<n;i++)
        {
            currSum+=arr[i];
            if(currSum==targetSum)
            {
                currSum=0;
                for(int j=i+1;j<n;j++)
                {
                    currSum+=arr[j];
                    if(currSum==targetSum)
                    {
                        if(j==n-1)
                        return false;
                        else
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};