class Solution 
{
public:
    
   int maxDiff(int num) 
    {
        string s = to_string(num);
    const int n = s.length();
    string n1(s);
    string n2(s);
    s += '#'; // append an unmatchable char to avoid out_of_bound.
    int x = 0;
    int y = 0;
    while (x < n && (s[x] == '0' || s[x] == '1')) ++x;
    while (y < n && s[y] == '9') ++y;    
    for (char& c : n1)
      if (c == s[x]) c = x ? '0' : '1';
    for (char& c : n2)
      if (c == s[y]) c = '9';    
    return stoi(n2) - stoi(n1);
    }
};