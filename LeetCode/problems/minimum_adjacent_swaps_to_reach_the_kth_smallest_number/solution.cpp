class Solution {
public:
    int getMinSwaps(string num, int k) {
        
        //next permutation is alwys greater than the previous one
        //e.g. first permutation = 12345 -> last perm 54321
        string original=num;
        while(k--) next_permutation(num.begin(),num.end());
        
        //bring every element from initial position to desired position
        int count=0;
        for(int j=0;j<num.size();j++)
        {
            if(num[j]!=original[j])
            {
                int i=j;
                while(original[i]!=num[j]) i++;
                while(num[j]!=original[j])
                {
                    swap(original[i],original[i-1]);
                    count++;
                    i--;
                }
            }
        }
        return count;
        
    }
};