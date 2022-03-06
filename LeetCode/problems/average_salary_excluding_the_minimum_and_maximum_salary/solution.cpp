//::Pradeepto Sarkar LC1491:://

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int n=salary.size();
        double sum=0;
        for(int i=1;i<n-1;i++)
            sum+=salary[i];
        return double(sum/(n-2));
    }
};