class Solution {
public:
    int minSwapsCouples(vector<int> row) {
        int n = (int)row.size();
        map<int,int> mp;
        for(int i = 0;i < n;i++){
            mp[row[i]] = i;
        }
        int ans = 0;
        for(int i = 0;i < n;i+=2){
            int pre = row[i];
            int req = row[i] + 1;
            if(row[i]&1){
                req -= 2;
            }
            if(mp[req] == i+1){
                continue;
            }
            else{
                int plc = mp[req];
                mp[req] = i+1;
                mp[row[i+1]] = plc;
                row[plc] = row[i+1];
                row[i+1] = req;
                ans++;
            }
        }
        return ans;
    }
};