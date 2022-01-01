class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
	int idx = n-1;

	// Step 1
	while(idx >= 1) {
		if(nums[idx] > nums[idx-1]) {
			// Step 2
			reverse(nums.begin()+idx, nums.end());

			// Step 3
			for(int i=idx; i<n; i++) {
				if(nums[i] > nums[idx-1]) {
					swap(nums[i], nums[idx-1]);
					break;
				}
			}
			break;
		}
		idx--;
	}

	// Step 4
	if(idx == 0) 
		reverse(nums.begin(), nums.end());
	

    }
};