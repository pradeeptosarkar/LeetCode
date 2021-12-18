class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans=s;
        int n= indices.size();
        for (int i=n-1; i>=0; i--)
        {
            int x= indices.back();
            ans[x]=s[i];
            indices.pop_back();
        }
        return ans;
    }
};