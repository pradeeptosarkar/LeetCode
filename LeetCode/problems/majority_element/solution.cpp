//::Pradeepto Sarkar LC169 26/02/2022:://

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        nth_element(nums.begin(), nums.begin()+(nums.size()/2), nums.end());
	    return *(nums.begin() + (nums.size()/2));
    }
};