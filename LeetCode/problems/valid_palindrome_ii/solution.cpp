class Solution {
public:
    bool validPalindrome(string s) {
     int left = 0, right = s.size()-1, flag = 1;
        return validHelper(s, left, right, flag);
    }
    bool validHelper(string& s, int left, int right, int flag) {
        if(left >= right) 
            return true;
        
        else if(s[left] == s[right]) 
            return validHelper(s, left+1, right-1, flag);
        
        else if(flag) 
            return validHelper(s, left+1, right, flag-1) || validHelper(s, left, right-1, flag-1);
        
        return false;
       
    }
};