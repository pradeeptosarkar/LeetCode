class Solution {
public:
    vector<long long> sumOfThree(long long num) 
    {
        vector<long long> ans;
        
        if(num%3==0)
        {
            long long n=num/3;
            ans.push_back(n-1);
            ans.push_back(n);
            ans.push_back(n+1);
        }
        return ans;
        
    }
};