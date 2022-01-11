class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
      int ans = 0;
        for(int i = 0, n = arr.size(); i < n; i++)
            ans += ((i+1)*(n-i)+1)/2 * arr[i];
        return ans;  
    }
};