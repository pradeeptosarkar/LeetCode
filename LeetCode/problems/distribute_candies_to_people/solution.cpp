class Solution {
public:
    vector<int> distributeCandies(int c, int np) 
    {
       
        vector<int> ans(np, 0);  // Required vector
        int i = 0, cc = 1, p_cc = 1;  // i = index, cc = collected candy, p_cc = previously collected candy
        while(c) {
            if(cc > c) {  // If candies are less then required then assign remaining and return ans.
                ans[i] += c;
                return ans;
            }
            ans[i++] += cc;  // Candies collected by a person
            c -= cc;  // Remaining candies
            if(i == np) {  // If current round is over
                i = 0;
                cc = p_cc + np;  // New collected candies
                p_cc = cc;
                continue;
            }
            cc++;  // Everytime one more candy will be given to the next person
        }
        return ans;
    }
};