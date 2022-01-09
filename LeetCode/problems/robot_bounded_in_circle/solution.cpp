class Solution {
public:
    const int
        NORTH = 0,
        EAST = 1,
        SOUTH = 2,
        WEST = 3;


    bool isRobotBounded(string instructions) {
        int x = 0, y = 0; // init position;
        int dir = NORTH;
        for(int i = 0; instructions[i]; i++) {
            if (instructions[i] == 'L') {
                dir = (dir - 1 + 4) % 4;
            } else if (instructions[i] == 'R') {
                dir = (dir + 1 + 4) % 4;
            } else {
                switch(dir) {
                    case 0:
                        y += 1;
                        break;
                    case 2:
                        y -= 1;
                        break;
                    case 3:
                        x -= 1;
                        break;
                    case 1:
                        x += 1;
                        break;
                }
            }
        }
        if ((x != 0 || y != 0) && dir == NORTH)
            return false;
        return true;
    }
};