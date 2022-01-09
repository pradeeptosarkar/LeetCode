class Solution {
private:
    vector<int>generate_candidates(){
        vector<int>cnd;
        cnd.push_back(0);
        cnd.push_back(1);
        return cnd;
    }
    void backtrack(vector<int>&nums,vector<int>subset,int k,int &sum){
        if(k==nums.size()){
            int subset_xor=0;
            for(int i=0;i<subset.size();i++){
                subset_xor=subset_xor^subset[i];
            }
            sum+=subset_xor;
        } else {
            vector<int>cnd=generate_candidates();
            for(int i=0;i<cnd.size();i++){
                if(cnd[i]==1){
                    subset.push_back(nums[k]);
                    backtrack(nums,subset,k+1,sum);
                    subset.pop_back();
                } else {
                    backtrack(nums,subset,k+1,sum);
                }
            }
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int>subset;
        int sum=0;
        backtrack(nums,subset,0,sum);
        return sum;
    }
};