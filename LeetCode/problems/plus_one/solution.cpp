class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, j = 1, carry = 0, sum = 0, first;
        vector<int> vect;
        i = digits.size() - 1;
        
        while(i != -1 || j != 0 || carry){
            if(i != -1) first = digits[i--];
            else first = 0;
            
            sum =  first + j + carry;
            vect.push_back(sum % 10);
            carry = sum / 10;
            j = 0;
        }
        reverse(vect.begin(), vect.end());
        return vect;
    }
};