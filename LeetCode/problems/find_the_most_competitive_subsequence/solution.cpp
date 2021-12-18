class Solution {
public:
    vector<int> mostCompetitive(vector<int>&A, int k) {
        int n = A.size();
        stack<int>S;
        vector<int>res;
        for(int i = 0; i < n; i++)
        {
            while(!S.empty() and S.size() + (n - i) > k and S.top() > A[i])
            {
                S.pop();
            }
            if(S.size() < k)
                S.push(A[i]);
        }
        while(!S.empty())
        {
            res.push_back(S.top());
            S.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};