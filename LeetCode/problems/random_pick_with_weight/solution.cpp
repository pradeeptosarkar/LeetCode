class Solution {
public:
    Solution(vector<int>& w) {
       sum_weight = 0;
       for (int i : w) {
        sum_weight += i;
        ws.push_back(sum_weight);
       } 
    }
    
    int pickIndex() {
        int r = rand()%ws.back();
        int left =0, right = ws.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (r >= ws[mid]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return left;
    }
    
    int sum_weight;
    vector<int> ws;
};