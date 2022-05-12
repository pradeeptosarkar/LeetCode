class Solution {
public:
    unordered_map<int,int> mymap;
    int mod = 1e9 + 7;
    int base = 37;
    vector<vector<int> > ans;
    vector<int> temp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) nums[i] = nums[i] + 10;
        solve(nums, 0, 0);
        return ans;
    }
    
    void solve(vector<int>& nums, int mask, int hashValue){
        int n = nums.size();
        if(mask == (1<<n)-1){
            if(!mymap[hashValue]){
                ans.push_back(temp);
                mymap[hashValue]++;
            }
            return;
        }
        
        for(int i=0;i<n;i++){
            if( !(mask & (1<<i)) ){
                long long t = hashValue * 1ll * base + nums[i];
                if(t>=mod) t %= mod;
                temp.push_back(nums[i] - 10);
                solve(nums, mask | (1<<i), t);
                temp.pop_back();
            }
        }
    }
};