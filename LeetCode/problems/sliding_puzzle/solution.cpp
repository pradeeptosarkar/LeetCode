class Solution 
{
public:
    vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                start += to_string(board[i][j]);
            }
        }
        
        //cout << "start is " << start << endl;
        queue<pair<string, int>> myq;
        myq.push({start, 0});
        unordered_set<string> visited;
        visited.insert(start);
        
        while (!myq.empty()) {
            auto top = myq.front();
            myq.pop();
            string s = top.first;
            int n = top.second;
            //cout << s << " " << n << endl;
            if (s == "123450") {
                return n;
            }
            
            int i;
            for (i = 0; i < 6; i++) {
                if (s[i] == '0')
                    break;
            }
    
            for (auto d : dir[i]) {
                char c = s[d];
                s[i] = c;
                s[d] = '0';
                if (visited.find(s) == visited.end()) {
                    myq.push({s, n+1});
                    visited.insert(s);
                }
                s[d] = c;
                s[i]= '0';
            }
        }
        
        return -1;
    }
};