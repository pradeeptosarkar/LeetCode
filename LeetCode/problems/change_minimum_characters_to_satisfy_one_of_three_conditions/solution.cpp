class Solution
{
    public:
        int minCharacters(string a, string b)
        {
            int cona[26] = {};
            int conb[26] = {};
            int n = a.size(), m = b.size();
            for (auto c: a) cona[c - 'a']++;
            for (auto c: b) conb[c - 'a']++;
            int res = INT_MAX;
            
            //   make all letters equals to  1 characters   here checking for all  letters from 'a to z' 
            //   and taking that characters with minimum change
            for (int i = 0; i < 26; i++)
            {
                res = min(res, n + m - (cona[i] + conb[i]));
            }
             //     string   a    all letters <=i   for  a<=i<=y   and string b all letters >i;
            for (int i = 0; i < 25; i++)
            {
                int count = 0;
                for (int j = 0; j < n; j++)
                {
                    if (a[j] > 'a' + i)
                    {
                        count++;
                    }
                }
                for (int j = 0; j < m; j++)
                {
                    if (b[j] <= 'a' + i)
                    {
                        count++;
                    }
                }
                res = min(res, count);
            }
            
            //     string   a    all letters >i   for  a<=i<=y   and string b all letters <=i;
            for (int i = 0; i < 25; i++)
            {
                int count = 0;
                for (int j = 0; j < m; j++)
                {
                    if (b[j] > 'a' + i)
                    {
                        count++;
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    if (a[j] <= 'a' + i)
                    {
                        count++;
                    }
                }
                res = min(res, count);
            }
            
            //return minimum change;
            return res;
        }
};