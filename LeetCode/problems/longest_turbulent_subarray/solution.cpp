class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int>ans;
        int len = 0;
        int curr = 0;
        for(int i = 1;i < arr.size(); i++) {
            if(arr[i] == arr[i-1]) {
                ans.push_back(-1);
            }
            else if(arr[i] > arr[i-1]) {
                ans.push_back(1);
            }
            else {
                ans.push_back(0); 
            }
        }
        for(int j = 0;j < arr.size() - 1; j++) {
            if(j == 0 && ans[j] != -1){
                curr++;
            }
            else if(ans[j] == -1) {
                curr = 0;
            }
            else{
                if(ans[j] != ans[j-1])
                   curr++;
                else {
                    curr=1;
                }
            }
            len = max(len, curr);
        }
        return len+1;
    }
};