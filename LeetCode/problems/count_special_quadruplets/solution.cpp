class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
     int n=nums.size(),c=0;
        unordered_map<int,int>freq;
        reverse(begin(nums),end(nums));
        freq[nums[0]]++;
        for(int i=1;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    c+=freq[nums[i]+nums[j]+nums[k]];
                }
            }
            freq[nums[i]]++;
        }
        return c;
    }
};