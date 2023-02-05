class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        make_heap(begin(gifts), end(gifts));
        while(k--) 
        {
            pop_heap(begin(gifts), end(gifts));
            gifts.back() = sqrt(gifts.back());
            push_heap(begin(gifts), end(gifts));
        }
        return accumulate(begin(gifts), end(gifts), (long long)0);
    }
};