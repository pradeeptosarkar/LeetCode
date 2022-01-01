class Solution {
public:
    int maxArea(vector<int>& h) {
        int i,j;
        i=0;
        j=h.size()-1;
        int max=0;
        while(i<j)
        {
            int curr = (j-i) * min(h.at(i),h.at(j));
            if (curr>max) max=curr;
            if(h[i]<h[j])
                i++;
            else
                j--;
        }
        return max;
    }
};