class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
        unordered_map<int,int> mpp;
        
        int res=0,currsum=0,n=nums.size();
        
        for( auto &it:nums)
        {
            currsum+=it;
            
            // if currsum == k, then I found 1 subarray
            if(currsum==k)
            { res++; }
            
           /* WHY currsum-k ?
             Example Situation: k =7, currsum=0, count=0;
            
            After some iteration, currsum=7,  HASH =1, count++;
            After some iteration, currsum=13, SUB = currsum-k = 6, HASH =0 (not found)
            After some iteration, currsum=14, SUB = currsum-k = 7, HASH = HASH[currsum -k] = 7 (whose HASH is 1), count++;
           
            So, here I have dependent upon previous existence with count; 
            */
            
            
            if(mpp.count(currsum - k))
            {
                res+=mpp[currsum-k];
            }
            
            mpp[currsum]++;
        }
        
        
        return res;
    }
};