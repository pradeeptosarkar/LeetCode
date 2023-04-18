class Solution {
public:
    int addMinimum(string word) {
        string cat = "abc";
        int j = 0;
        int mod = 3;
        int ans = 0;

        for(int i = 0; i < word.size(); ) 
        {
            if(word[i] == cat[j]) 
                i++;
             else 
                ans++; 
            
            j = (j+1) % mod;
        }

        if(j == 0) return ans;
        return ans-j+3;
    }
};