#define ll long long
class Solution {
public:
        int firstMissingPositive(vector<int>& nums) {
        vector <int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0)
                {if(nums[i]>0&&nums[i]!=nums[i-1])
                {
                    ans.push_back(nums[i]);
                }}
            else if(nums[i]>0)
            {
                ans.push_back(nums[i]);
            }
        }
        if(ans.empty())
        {
            return 1;
        }
        ll a=ans[ans.size()-1]+1*1ll;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]-i!=1)
            {
                a=i+1;
                break;
            }
        }
        return a;
    }
};