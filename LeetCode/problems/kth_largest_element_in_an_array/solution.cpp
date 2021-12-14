class Solution {
public:
    int findKthLargest(vector<int>& v1, int k) {
        int n = v1.size();
        sort(v1.begin(),v1.end());
        
        return v1[n-k];
    }
};