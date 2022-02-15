/*class Solution {
public:
    int integerBreak(int n) {
        
    }
};
   
    

343. Integer Break

Description

Hints

Submissions

Discuss

Solution

      

C++ | Simple Solution using Memoization

C++ | Simple Solution using Memoization

7

VIEWS

0

Created at: 16 hours ago

__priyanshu__

__priyanshu__

 20*/

class Solution {

public:

int integerBreak(int n) {

    if(n == 0)

        return 1;

    

    int ans = 0;

    unordered_map<int, int> mp;

    for(int i = 1; i < n; i++)

        ans = max(ans, i * integerBreak(n - i, mp));

    

    return ans;

}

int integerBreak(int n, unordered_map<int, int> &mp)

{

    if(n == 0)

        return 1;

    

    if(mp.find(n) != mp.end())

        return mp[n];

    

    int ans = 0;

    for(int i = 1; i <= n; i++)

        ans = max(ans, i * integerBreak(n - i, mp));

    

    return mp[n] = ans;

}

};