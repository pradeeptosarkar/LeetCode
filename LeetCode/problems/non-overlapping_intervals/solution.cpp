class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& iv) {
     sort(iv.begin(),iv.end());
        int l = iv[0][0];
        int r = iv[0][1];
        int cnt = 0;
        for(int i=1;i<iv.size();i++){
            if(iv[i][0] >= r){
                l = iv[i][0];
                r = iv[i][1];
            }else{
                r = min(r,iv[i][1]);
                cnt++;
            }
        }    
        return cnt;   
    }
};