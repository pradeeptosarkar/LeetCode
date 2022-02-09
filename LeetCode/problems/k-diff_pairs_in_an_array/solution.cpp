/*class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
    }
};*/
    
    class Solution {

public:

    int findPairs(vector<int>& nums, int k) {

        if (k < 0)

            return 0;

        

        unordered_map<int, int> m;

        for (int num : nums)

            ++m[num];

        

        int ans = 0;

        for (auto &p : m) {

            if (k)

                ans += m.count(p.first + k);

            else

                ans += p.second > 1;

        }

        return ans;

    }

};