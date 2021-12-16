class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i, j, carry = 0, sum = 0, first;
        vector<int> vect;
        i = num.size() - 1;
        
        while(i != -1 || k != 0 || carry){
            if(i != -1) first = num[i--];
            else first = 0;
        
            if(k != 0){
                j = k % 10;
                k = k / 10;
            }
            else j = 0;
            
            sum =  first + j + carry;
            vect.push_back(sum % 10);
            carry = sum / 10;
        }
        reverse(vect.begin(), vect.end());
        return vect;
    }
};