class Solution {
public:
    bool isFascinating(int n) 
    {
        string ans=to_string(n)+to_string(2*n)+to_string(3*n);
        sort(ans.begin(), ans.end());
        return ans=="123456789";
    }
};