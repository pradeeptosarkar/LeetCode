class Solution {
public:
    
    void findCombi(int idx, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int>temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx and candidates[i]==candidates[i-1])
                continue;
            
            if(candidates[i]>target)
                break;
            
            temp.push_back(candidates[i]);
            findCombi(i+1, target-candidates[i], candidates, ans, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        findCombi(0, target, candidates, ans, temp);
        return ans;
        
    }
};