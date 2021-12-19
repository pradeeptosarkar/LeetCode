struct Token {
    string name;
    int val;
};

class Solution {
    // Extract an element beginning with a capital letter and increment the index
    auto extractName(const string& formula, int& i) {
        string name;
        name.push_back(formula[i++]);
        while (i < formula.size() && islower(formula[i])) {
            name.push_back(formula[i++]);
        }
        
        return name;
    }
    
    // Extract a count (or return 1) and increment the index
    auto extractCount(const string& formula, int& i) {
        int count = 0;
        while (i < formula.size() && isdigit(formula[i])) {
            count = count * 10 + formula[i++] - '0';
        }
        
        return count == 0 ? 1 : count;
    }
    
    void multiplyBlock(vector<Token>& st, int count) {
        vector<Token> block;
        while (st.back().name != "(") {
            block.push_back(st.back());
            st.pop_back();
        }
        st.pop_back(); // Remove the "("

        // Multiply block by count and put it back on the stack
        for (auto& token: block) {
            token.val *= count;
            st.push_back(token);
        }
    }
    
    auto generateResult(vector<Token>& st) {    
        // Generate result. Merge repeating tokens and sort
        unordered_map<string, int> counts;
        for (auto& token: st) {
            counts[token.name] += token.val;
        }
        
        vector<pair<string, int>> vec(begin(counts), end(counts));
        sort(begin(vec), end(vec), [](auto& a, auto& b) {
            return a.first < b.first;
        });
        
        string res;
        for (auto& p: vec) {
            res += p.first;
            if (p.second > 1) {
                res += to_string(p.second);
            }
        }
        
        return res;
    }
    
public:
    string countOfAtoms(string formula) {
        vector<Token> st;
        
        int i = 0;
        
        for (; i < formula.size();) {
            // Beginning of element found
            if (isupper(formula[i])) {
                auto name = extractName(formula, i);
                auto count = extractCount(formula, i);                
                st.push_back({name, count});
            } 
            // Handle opening
            else if (formula[i] == '(') {
                st.push_back({"(", 0});
                ++i;
            }
            // Handle closing
            else if (formula[i] == ')') {
                ++i; // Skip ")"
                auto count = extractCount(formula, i);
                multiplyBlock(st, count);
            }
        }
                
        return generateResult(st);
    }
};
