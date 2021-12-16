class Solution {
public:
    bool isPerfectSquare(int num) {
        int srt = sqrt(num);

		if(srt * srt == num) return true;
		return false;
    }
};