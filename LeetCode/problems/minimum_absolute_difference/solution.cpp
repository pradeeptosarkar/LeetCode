class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        int mini=INT_MAX;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-arr[i-1] < mini){
                ans.clear();
                ans.push_back({arr[i-1], arr[i]});
                mini = arr[i] - arr[i-1];
            }else if(arr[i]-arr[i-1] == mini) ans.push_back({arr[i-1], arr[i]});
        }
        
        return ans;
    }
};