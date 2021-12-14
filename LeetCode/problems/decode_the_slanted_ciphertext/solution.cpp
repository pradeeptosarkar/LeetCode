class Solution {
public:
    string decodeCiphertext(string s, int row) {
        int col = s.size() / row;
        string ans;
        for (int i = 0; i < col; ++i) { // start from each column
            for (int x = i, y = 0; x < col && y < row; ++x, ++y) ans += s[y * col + x]; // traverse the string diagonally
        }
        while (ans.size() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};