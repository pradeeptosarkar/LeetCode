class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        
        if(n==1)
            return ans;
        
        else
        {
            for(int i=2;i<=n;i++)
            {
                int temp=pow(2,i-1);
                for(int j=temp-1;j>=0;j--)
                    ans.push_back(ans[j]+temp);
            }
        }
        return ans;
    }
};