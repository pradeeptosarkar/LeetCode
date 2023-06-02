class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int max = m + n - 1;
		int i = m - 1;
		int j = n - 1;
        
		while (i >= 0 && j >= 0) 
        {
			if (nums2[j] > nums1[i]) 
                nums1[max--] = nums2[j--];
            
			else 
                nums1[max--] = nums1[i--];
		}
		while (j >= 0)nums1[max--] = nums2[j--];
    }
};