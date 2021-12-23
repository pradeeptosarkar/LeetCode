class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<bool> used(n,0);
        vector<vector<int> > res;
        vector<int>tmp;
        solve(1,k,n, used,res,tmp);
        return res;
    }
    void solve( int idx,int k , int n , vector<bool>&used, vector<vector<int> >&res 
    ,vector<int> &tmp ){
        if(tmp.size()==k){
    
            res.push_back(tmp);
            return ;
        }
        for(int i=idx;i<=n;i++){
            if(!used[i]){
                used[i]=1;
                tmp.push_back(i); // here we are using simple permutation concepts-> lets say we have 
                // k places  - - - - , so in first place we have n options then for second we are left with n-1 options then n-2 and so on .... till k  
                solve(i+1,k,n,used,res,tmp);
                used[i]=0;
                tmp.pop_back();
            }
        }
    }
};