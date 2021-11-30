class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev;

        for (int i = 1; i <= numRows; i++) {
            vector<int> now;
            now.push_back(1);
            for (int j = 1; j < i-1; j++) {
                int preVal = prev.at(j - 1);
                int nowVal = prev.at(j);
                now.push_back(preVal + nowVal);
            }
            if(i>1)
                now.push_back(1);

            res.push_back(now);
            prev = now;
        }
        return res;
    }
};