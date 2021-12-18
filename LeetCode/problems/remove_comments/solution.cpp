class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
	bool multilinecomment = false;
	string curr = "";
	for(int line=0;line<source.size();line++)
	{
		int len = source[line].length();
		for(int i=0;i<source[line].length();i++)
		{
			if(multilinecomment)
			{
				if(i<len-1 && source[line][i]=='*' && source[line][i+1]=='/')
				{
					multilinecomment = false;
					i++;
				}
			}
			else
			{
				if(i<len-1 && source[line][i]=='/' && source[line][i+1]=='/')
					goto next;
				else if(i<len-1 && source[line][i]=='/' && source[line][i+1]=='*')
				{
					multilinecomment = true;
					i++;
				}
				else
				{
					curr += source[line][i];
				}
			}
		}

		next:
		if(!multilinecomment && curr!="")
		{
			res.push_back(curr);
			curr = "";
		}
	}

	return res;
    }
};