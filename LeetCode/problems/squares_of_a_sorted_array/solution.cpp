class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
      vector<int> ans(A.size());
    auto e = prev(end(A));
    auto s = begin(A);
    auto it = end(ans);
    while (--it >= begin(ans)) {
      if (e > s && abs(*e) > abs(*s))
        *it = pow(*e--, 2);        
      else
        *it = pow(*s++, 2);
    }
    return ans;  
    }
};