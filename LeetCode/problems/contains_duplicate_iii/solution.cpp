class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (size(nums) < 2) return false; // handling edge cases
        
		vector<pair<int, int>> mp; // map that stores value and its index
        
		for (int i = 0; i < size(nums); i++) mp.push_back({nums[i], i}); // generating map -> O(n)
        
		sort(begin(mp), end(mp)); // sort the map according to value -> O(nlogn)
        
		for (int l = 0, r = 1; r < size(nums); r++) { // sliding window that goes from [l to r] with maximum difference t between mp[l] and mp[r]
            
			while ((long long)(mp[r].first) - mp[l].first > t)  l++; // resize the window to include mp[r] in the window -> O(n)
            
			if (r - l >= 1) { // no need to check if length is less than 2
                
				auto v = vector(cbegin(mp) + l, cbegin(mp) + r + 1); // copy the window -> O(n)
				
				// sort the copy according to index -> O(nlogn)
                sort(begin(v), end(v), [](const auto& a, const auto& b) { return a.second < b.second; });
				
				// if there are any two adjacent indices with difference <= k return true
                if (adjacent_find(cbegin(v), cend(v), [&](const auto& a, const auto& b) { return b.second - a.second <= k; }) != cend(v)) return true;
            }
        } // -> O(n)
        return false;
    }
};