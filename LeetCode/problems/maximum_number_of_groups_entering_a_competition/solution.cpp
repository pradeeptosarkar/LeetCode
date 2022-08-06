class Solution {
public:
    int maximumGroups(vector<int>& grades) 
    {
        double x=1-4*(-2*grades.size());
        double squareRoot=sqrt(abs(x));
        int ans=(squareRoot-1)/2;
        return ans;
    }
};