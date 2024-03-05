class Solution {
public:
    int minimumLength(string s) {
        return deleteSimilarEnds(s, 0, s.length() - 1);
    }
private:
     
    int deleteSimilarEnds(string &s, int begin, int end) {
        
        if (begin >= end || s[begin] != s[end]){
            return end - begin + 1;
        } else {
            char c = s[begin];

            
            while (begin <= end && s[begin] == c)
                begin++;

            
            while (end > begin && s[end] == c)
                end--;

            return deleteSimilarEnds(s, begin, end); 
        }  
    }
};
