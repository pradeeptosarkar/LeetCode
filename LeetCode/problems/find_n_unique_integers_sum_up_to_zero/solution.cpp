class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n, 0);
        int left = 0, right = n - 1;
        int start = 1;
        while (left < right) {
            res[left++] = start;
            res[right--] = -start;
            start++;
        }
        return res;
    }
};