class Solution {
public:
bool is_valid(unordered_map<char,int> &arr)
{
for(auto it=arr.begin(); it!=arr.end(); it++)
{
if((it->second)>1)
{
return false;
}
}
return true;
}
int lengthOfLongestSubstring(string s)
{ unordered_map<char,int>arr;
int n=s.length();
int i;
int j=0;
int k=0;
int max=0;
while(j<n)
{
k=0;
for(i=j; i<n; i++)
{ arr[s[i]]++;
if(is_valid(arr))
{
k++;
}
else
{ for(auto it=arr.begin(); it!=arr.end(); it++)
{
it->second=0;
}
j++;
break;
}
}
if(k>max)
max=k;
}
return max;
}
};