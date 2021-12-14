class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for(int i=0; i<arr1.size(); i++) {
            bool found_err = false;
            for(int j=0; j<arr2.size() && !found_err; j++) {
                if( abs( arr1[i] - arr2[j] ) <= d ) found_err = true;
            } res += found_err ? 0 : 1;
        } return res;
    }
};