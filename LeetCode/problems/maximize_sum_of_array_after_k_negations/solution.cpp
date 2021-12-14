class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        vector<int>neg;
        vector<int>ans;
        bool z = false;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            else
                ans.push_back(nums[i]);
            if(nums[i] == 0)
                z = true;
        }
        sort(neg.begin(),neg.end());
        for(int i = 0;i<neg.size() and k>0;i++)
        {
            neg[i] *= -1;
            k--;
        }
        for(int i = 0;i<neg.size();i++)
        {
            ans.push_back(neg[i]);
        }
        k %= 2;
        if(k == 0)return accumulate(ans.begin(),ans.end(),0);
        if(k)
        {
            if(z)
            {
                return accumulate(ans.begin(),ans.end(),0);
            }
        }
        int mn = *min_element(ans.begin(),ans.end());
        for(int i = 0;i<ans.size();i++)
        {
            if(ans[i] == mn)
            {
                ans[i] *= -1;
                break;
            }
        }
        int sum = accumulate(ans.begin(),ans.end(),0);
        return sum;
    }
};