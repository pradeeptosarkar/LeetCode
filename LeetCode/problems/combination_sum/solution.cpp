class Solution {
public:
    
    void findCombination(int idx, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&temp)
    {
        if(idx==candidates.size())
        {
            if(target==0)
                ans.push_back(temp);
            return;
        }
        
        if(candidates[idx]<=target)
        {
            temp.push_back(candidates[idx]);
            findCombination(idx, target-candidates[idx], candidates, ans, temp);
            
            temp.pop_back();
        }
        findCombination(idx+1, target, candidates, ans, temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        findCombination(0,target,candidates,ans,temp);
        return ans;
        
    }
};