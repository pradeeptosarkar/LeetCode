class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size();
        vector<int> pairWeights(n - 1, 0);
        
        for (int i = 0; i < n - 1; ++i) 
            pairWeights[i] += weights[i] + weights[i + 1];
        
        long long answer = 0;
        sort(pairWeights.begin(), pairWeights.end());
        
        for (int i = 0; i < k - 1; ++i) 
            answer += pairWeights[n - 2 - i] - pairWeights[i];
        
        return answer;
    }
};