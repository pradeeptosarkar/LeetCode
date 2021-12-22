class Solution {
public:
    // Using unordered set to avoid repeated patterns in the final answer.
    unordered_set<string> ust;
    void helper(string& s, int idx, int rl, int rr, string res, int balance) {
        if(balance < 0) return ;    // At any moment we cannot have count of right parentheses greater than count of left ones.
        if(idx == s.size()) {
            if(rl == 0 && rr == 0 && balance == 0) ust.insert(res);
            return ;
        }
        // We have two options- Either take the current char or dont take it.
        // We are excluding the current character if we are allowed to do so.
        if(s[idx] == '(' && rl > 0) helper(s, idx+1, rl-1, rr, res, balance);
        if(s[idx] == ')' && rr > 0) helper(s, idx+1, rl, rr-1, res, balance);
        // If we are taking current char then we have to update balance.
        // balance = diff between the count of left and right parentheses- we should not have negative balance.
        if(s[idx] == '(') balance++;
        else if(s[idx] == ')') balance--;
        // Taking current character in the res.
        helper(s, idx+1, rl, rr, res+s[idx], balance);
        return ;
    }
    vector<string> removeInvalidParentheses(string s) {
        int rl = 0, rr = 0;
        // rl = number of invalid left parentheses.
        // rr = number of invalid right parentheses.
        for(auto ch: s) {
            if(ch == '(') rl++;
            else if(ch == ')') {
                if(rl > 0) rl--;
                else rr++;
            }
        }
        helper(s, 0, rl, rr, "", 0);
        vector<string> ans = {ust.begin(), ust.end()};
        return ans;
    }
};