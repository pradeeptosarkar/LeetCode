class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    int prev = -1, cur = 0 , n = seats.size();
    int ans = 0;

    while (cur < n) {
        if (seats[cur] == 0) {
            cur++;
            continue;
        }
        if (prev == -1)
            ans = max(ans, cur - prev - 1);
        else
            ans = max(ans, (cur - prev) / 2);
        prev = cur;
        cur++;
    }
    ans = max(ans , cur - prev - 1);
    return ans;
    }
};