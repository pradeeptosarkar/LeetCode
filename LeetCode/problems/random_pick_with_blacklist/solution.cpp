class Solution {
public:
    Solution(int n, vector<int>& blacklist):n(n) {
        b = blacklist;
        sort(b.begin(), b.end());
    }
    
    int pick() {
        int k = rand()%(n-b.size());
        if (b.empty()) {
            return k;
        }
        int left=0, right=b.size()-1;
        while (left<=right) {
            int mid = left + (right-left)/2;
            if (k >= b[mid]-mid) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return k+left;
    }
    
    int n;
    vector<int> b;
};
