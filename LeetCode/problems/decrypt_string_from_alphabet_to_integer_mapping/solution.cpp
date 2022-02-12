class Solution {
public:
string freqAlphabets(string s) {
string ans;
for(int i=0;i<s.size();i++)
{
if(i<s.size()-2 && s[i+2]=='#')
{
ans+='j'+(s[i]-'1')*10+s[i+1]-'0';
i+=2;
}
else
{
ans+='a'+s[i]-'1';
}
}
return ans;

}
};