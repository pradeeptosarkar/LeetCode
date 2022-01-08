class Solution 
{
public:
    bool canJump(vector<int>& A) 
    {
        int i = 0;
        for (int reach = 0; i < A.size() && i <= reach; ++i)
           reach = max(i + A[i], reach);
        return i == A.size(); 
    }
};