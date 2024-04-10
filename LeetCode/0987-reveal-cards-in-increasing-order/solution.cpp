class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> result(n);
        queue<int> indices;
        for (int i = 0; i < n; i++) { indices.push(i); }
        for (int card : deck) {
            int idx = indices.front(); indices.pop();
            result[idx] = card;
            if (!indices.empty()) { indices.push(indices.front()); indices.pop(); }
        }
        return result;
    }
};
