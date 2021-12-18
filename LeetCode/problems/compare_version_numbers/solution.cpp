class Solution {
public:
    int compareVersion(string version1, string version2) {
        int result = 0;
		int first1 = 0, last1 = 0, first2 = 0, last2 = 0;

		while (last1 <= version1.length() && last2 <= version2.length())
		{
			if (0 != last1)
			{
				first1 = last1 + 1;
			}

			if (0 != last2)
			{
				first2 = last2 + 1;
			}

			if (first1 >= version1.length() || first2 >= version2.length())
			{
				break;
			}

			if (version1.npos == (last1 = version1.find('.', first1)))
			{
				last1 = version1.length();
			}

			if (version2.npos == (last2 = version2.find('.', first2)))
			{
				last2 = version2.length(); 
			}

			if (0 != (result = compareReversion(version1, first1, last1 - 1, version2, first2, last2 - 1)))
			{
				break;
			}
		}

		if (0 == result)
		{
			if (first1 >= version1.length() && first2 >= version2.length())
			{
				result = 0;
			}
			else if(first1 >= version1.length())
			{
				if (!allZero(version2, first2))
				{
					result = -1;
				}
			}
			else if (first2 >= version2.length())
			{
				if (!allZero(version1, first1))
				{
					result = 1;
				}
			}
		}

		return result;
	}


	int compareReversion(string& version1, int first1, int last1,
		string& version2, int first2, int last2)
	{
		int result = 0;

		int begin1 = first1;
		int begin2 = first2;

		while (begin1 <= last1 && version1[begin1] == '0')
		{
			++begin1;
		}

		while (begin2 <= last2 && version2[begin2] == '0')
		{
			++begin2;
		}

		if (last1 - begin1 == last2 - begin2)
		{
			while (begin1 <= last1 && begin2 <= last2)
			{
				if (version1[begin1] != version2[begin2])
				{
					result = version1[begin1] > version2[begin2] ? 1 : -1;
					break;
				}
				else
				{
					++begin1;
					++begin2;
				}
			}
		}
		else if (last1 - begin1 > last2 - begin2)
		{
			result = 1;
		}
		else
		{
			result = -1;
		}

		return result;
	}

	bool allZero(string& version, int offset)
	{
		while (offset < version.length() && (version[offset] == '0' || version[offset] == '.'))
		{
			++offset;
		}

		return offset == version.length();
    }
};