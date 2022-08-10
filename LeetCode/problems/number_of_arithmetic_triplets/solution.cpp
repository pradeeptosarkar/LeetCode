class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        int ans=0;
		map<int,int>m;
		for(int i=0;i<nums.size();i++)
			m[nums[i]]++;
		for(auto &i:nums)
			if(i-diff>=0 && m[i-diff] && m[i-2*diff])
				ans++;
		return ans;      
    }
};