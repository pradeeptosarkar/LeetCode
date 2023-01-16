class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        unordered_map<int,int> freq;
        long long count = 0;
        long long ret = 0;
        int n = nums.size();
        int j = 0;
        for(int i=0; i<n; i++) 
        {
            int num = nums[i];
            count += freq[num];
            freq[num]++;
            while(count >= k && j<=i ) 
            {  
                ret += (n - i);
                num = nums[j];
                freq[num]--;
                count -= freq[num];
                j++;
            }
            
        }
        return ret;
    }
};