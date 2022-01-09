class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> f(nums.size());
        for(int i = 0; i < nums.size(); i++){
            f[i] = to_string(nums[i]);
        }
        sort(f.begin(), f.end(), [](const string &l, const string &r){
            return l + r > r + l;
        });
        string ans ="";
        for(auto i: f){
            if(f[0] == "0") return "0";
            ans += i;
        }
        return ans;
        
    }
};