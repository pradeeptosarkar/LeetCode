class Solution {
public:
    
    /*bool isvalid(unordered_map<char,int> &arr)
    {
        for(auto it=arr.begin();it!=arr.end();it++)
        {
            if((it->second)>1)
                return false;
        }
        return true;
    }*/
    
    int lengthOfLongestSubstring(string s) 
    {
     
        int max = 0, count = 0;
		 string res;
		 for (int i = 0; i < s.length(); i++)
		 {
			 if (res.find(s[i]) == -1)
			 {
				 res += s[i];
				 count++;
				 if (count > max)
					 max = count;
			 }
			 else
			 {
				 res.erase(res.begin(), res.begin() + res.find(s[i]) + 1);
				 res += s[i];
				 count = res.length();
			 }
		 }
		 return max;
    }
};