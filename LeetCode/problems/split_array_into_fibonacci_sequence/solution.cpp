class Solution {
    vector<int> ans;
    bool dfs(string num,int idx){
        if(idx==num.length()) return ans.size()>2;
        string s="";
        for(int i=idx;i<num.length();i++){
            if(num[idx]=='0' && i!=idx) return false;
            s+= num[i];
            if(stoll(s)>INT_MAX) break;
            int z=stoll(s);
            if(ans.size()<2 || (z-ans[ans.size()-2]==ans[ans.size()-1])){
                ans.push_back(z);
                if(dfs(num,i+1)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        if(dfs(num,0))  return ans;
        return vector<int>();
    }
};