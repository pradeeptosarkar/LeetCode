class Solution {
static bool sortcol(  vector<int>& v1,
                vector<int>& v2 ) {
 return v1[1] < v2[1];
}
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),sortcol);
        int l =1, prev = pairs[0][1];
        for(int i = 0;i<pairs.size();i++){
            if(pairs[i][0] > prev){
                l++;
                prev = pairs[i][1];
            }
        }
        return l;
    }
};