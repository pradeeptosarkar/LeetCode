class Solution {
    
    
private:
    int countSteps(int curr, int next, int ringLength) 
    {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        
        return 
            min(stepsBetween, stepsAround);
    }

public:
    int findRotateSteps(string ring, string key) 
    {
        int ringLen = ring.length();
        int keyLen = key.length();
        vector<int> curr(ringLen, 0);
        vector<int> prev(ringLen, 0);
        fill(prev.begin(), prev.end(), 0);
        
        for (int keyIndex = keyLen - 1; keyIndex >= 0; keyIndex--) {
            fill(curr.begin(), curr.end(), INT_MAX);
            for (int ringIndex = 0; ringIndex < ringLen; ringIndex++) {
                for (int charIndex = 0; charIndex < ringLen; charIndex++) {
                    if (ring[charIndex] == key[keyIndex]) {
                        curr[ringIndex] = min(curr[ringIndex],
                                1 + countSteps(ringIndex, charIndex, ringLen) + prev[charIndex]);
                    }
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};
