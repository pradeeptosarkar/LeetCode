class Solution {
public:
    vector<vector<int>> keys = {
        { 'a','b','c' }, { 'd','e','f' }, { 'g','h','i' }, { 'j','k','l' }, 
        { 'm','n','o' }, { 'p','q','r','s' }, { 't','u','v' }, { 'w','x','y','z' }
    };
    vector<string> ans;
	
    void letterHelper(string temp, string d, int i, int n){
        if(i >= n){
            ans.push_back(temp);
            return;
        }
        for(char x: keys[d[i]-'2']){
            letterHelper(temp+x,d,i+1,n);
        }
    }
	
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        letterHelper("",digits,0,digits.length());
        return ans;
    }
};