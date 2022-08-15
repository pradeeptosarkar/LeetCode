class Solution {
public:
    int help (map<int, int> & right, map<int, int> & left, int k)
    {
        right[0] = 0; 
        left[-1] = 0; 
        int ans = 0; 
        for (auto & i : right)
        {
            if (i.first == -1) continue; 
            int tmp = i.second; 
            int remain = k - i.first * 2; 
            auto it = left.upper_bound (remain); 
            it = prev (it); 
            tmp += it->second; 
            ans = max (ans, tmp); 
        }
        return ans; 
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        map<int, int> right, left; 
        int ans = 0; 
        int middle = 0; 
        for (int i = 0; i < fruits.size(); i++)
        {
            if (fruits[i][0] == startPos) middle = fruits[i][1]; 
            else if (fruits[i][0] > startPos && fruits[i][0] - startPos <= k)
                right[fruits[i][0] - startPos] = fruits[i][1]; 
            
            else if (fruits[i][0] < startPos && startPos - fruits[i][0] <=k)
                left[startPos - fruits[i][0]] = fruits[i][1]; 
        }
        
        int accu=0; 
        for (auto & i : right)
        {
            accu += i.second; 
            i.second = accu; 
        }
        accu = 0; 
        for (auto & i : left)
        {
            accu += i.second; 
            i.second = accu; 
        }
        return max (help(right, left, k),  help (left, right, k)) + middle; 
       
    }
};