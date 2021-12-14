// IDEA:
//  add: Mark all coordinates in a map
//  count:
//      1. Iterate the map and find if there is a point
//         in the same Y-axis of the query point
//      2. If yes, get the side length of square
//         by finding the Y-distance between the two points
//      3. For the above two points find if there is a point
//         on the same Y-axis with X-distance == side length respectively.
//      4. If both points exists, we can construct a square.
//      5. The result is multiplication of frequency of each point.
//
// NOTE:
//  Special cases that are not mentioned in the question
//  NOTE 1) if the query point already exists, the existing points do not contribute to the query result
//  NOTE 2) square with side length 0 is not counted as squares (4 points on same coordinates)
//
// Complexity Analysis
//  Time:
//    - add: average O(1) insertion to unordered_map
//    - count: O(n) since we have to traverse each point in the map (O(1) average time for unordered_map operations)
//  Space: O(n) due to storing each point in map

// pair hashing for unordered_map
struct HashPair {
public:
    size_t operator() (const pair<int, int> &p) const {
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);
        return h1 ^ h2;
    }
};

class DetectSquares {
private:
    unordered_map<pair<int, int>, int, HashPair> map;
public:
    DetectSquares() {
        
    }
    
	// Push each point into map
    void add(vector<int> point) {
        map[{point[0], point[1]}]++;
    }
    
    // NOTE: p1, p2, p3 represents point 0, 1, 2, 3 of square
    int count(vector<int> point) {
        int res = 0;
        int p0X = point[0];
        int p0Y = point[1];
        
        for (auto &p1It : map) {
            int p1X = p1It.first.first;
            int p1Y = p1It.first.second;
            
			// check if this point is on the same X-axis
            if (p1X == p0X) {
                int diff = abs(p0Y - p1Y);
                
                if (diff == 0) continue; // refer to NOTE 2
                
                // check left side and see if we can form a square
                auto p2It = map.find({p0X - diff, p0Y});
                auto p3It = map.find({p1X - diff, p1Y});
                if (p2It != map.end() && p3It != map.end()) {
                    res += (p1It.second * p2It->second * p3It->second);
                }
                
                // check right side and see if we can form a square
                p2It = map.find({p0X + diff, p0Y});
                p3It = map.find({p1X + diff, p1Y});
                if (p2It != map.end() && p3It != map.end()) {
                    res += (p1It.second * p2It->second * p3It->second);
                }
            }
        }
        return res;
    }
};