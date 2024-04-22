class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Map the next slot digit for each current slot digit.
        unordered_map<char, char> nextSlot = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };
        // Map the previous slot digit for each current slot digit.
        unordered_map<char, char> prevSlot = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };

        // Hash set to store visited and dead-end combinations.
        unordered_set<string> visitedCombinations(deadends.begin(), deadends.end());
        // Queue to store combinations generated after each turn.
        queue<string> pendingCombinations;

        // Count the number of wheel turns made.
        int turns = 0;

        // If the starting combination is also a dead-end, 
        // then we can't move from the starting combination.
        if (visitedCombinations.find("0000") != visitedCombinations.end()) {
            return -1;
        }

        // Start with the initial combination '0000'.
        pendingCombinations.push("0000");
        visitedCombinations.insert("0000");

        while (!pendingCombinations.empty()) {
            // Explore all the combinations of the current level.
            for (int currLevelNodesCount = pendingCombinations.size();
                 currLevelNodesCount > 0; --currLevelNodesCount) {
                // Get the current combination from the front of the queue.
                string currentCombination = pendingCombinations.front();
                pendingCombinations.pop();

                // If the current combination matches the target, 
                // return the number of turns/level.
                if (currentCombination == target) {
                    return turns;
                }

                for (int wheel = 0; wheel < 4; wheel += 1) {
                    string newCombination = currentCombination;
                    newCombination[wheel] = nextSlot[newCombination[wheel]];
                    
                    if (visitedCombinations.find(newCombination) == visitedCombinations.end()) {
                        pendingCombinations.push(newCombination);
                        visitedCombinations.insert(newCombination);
                    }

                    newCombination = currentCombination;
                    newCombination[wheel] = prevSlot[newCombination[wheel]];
                    if (visitedCombinations.find(newCombination) == visitedCombinations.end()) {
                        pendingCombinations.push(newCombination);
                        visitedCombinations.insert(newCombination);
                    }
                }
            }
            turns += 1;
        }
        
        return -1;
    }
};
