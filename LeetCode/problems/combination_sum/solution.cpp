class Solution {
public:
    
    void solve(vector<int>& temp, vector<int>& candidates, vector<vector<int>>& ans, int index, int target)
    {
        if(index==candidates.size())
        {
            if(target==0)
                ans.push_back(temp);
            
            return;
        }
        
        if(candidates[index]<=target)
        {
            temp.push_back(candidates[index]);
            solve(temp, candidates, ans, index, target-candidates[index]);
            temp.pop_back();
        }
        
        solve(temp, candidates, ans, index+1, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        //sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(temp, candidates, ans, 0, target);
        return ans;
    }
};