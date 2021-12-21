class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        sort(nums.begin(), nums.end(), [](const std::string &a, const std::string &b){
            // if the string have same length, e.g: "12" and "21"
            // sort them by default string comparison
            if (a.size() == b.size()) {
                return a < b;
            }
            // otherwise, using a simple length comparison
            return a.size() < b.size();
        });
        // since "nums" now sorted in non-decreasing order,
		// all we need is to get k-th index from back to front (nums.size() - k)
        return nums[nums.size() - k];
    }
};