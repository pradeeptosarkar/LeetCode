class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> answer(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            answer[i] = answer[i / 2] + i % 2;
        }
        
        return answer;
    }
};