class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		unordered_set<string> s(words.begin(), words.end());

		for (auto &e : s) {
			for (int i = 1; i < e.size(); ++i) {
				s.erase(e.substr(i));
			}
		}
		int ans = 0;
		for (auto &e : s) ans += e.size() + 1;
		return ans;
	}
};