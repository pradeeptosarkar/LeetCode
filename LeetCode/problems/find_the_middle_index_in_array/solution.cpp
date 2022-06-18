class Solution {
public:
    int findMiddleIndex(vector<int>& nums) 
    {
        int n=nums.size();
	
        if(n==1) 
        return 0;
	
        vector<int> pre(n);
        pre[0]=nums[0];
	
        for(int i=1;i<n;i++) 
            pre[i]=pre[i-1]+nums[i];
	
        int x=pre[n-1];

	for(int i=0;i<n;i++)
	{
		int left=pre[i]-nums[i];
		int right=x-pre[i];
		if(left==right)
			return i;
	}
	return -1;
        
    }
};