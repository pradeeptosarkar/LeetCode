class Robot {
    int x, y, w, h, dir;
    string dirstr[4] = {"East", "North", "West", "South"};
    
public:
    Robot(int width, int height) 
    {
        w = width-1, h = height-1, x = 0, y = 0, dir = 0;
    }
    
    void step(int num) 
    {
        if (dir==0)
            num += x + y;
        else if (dir==1)
            num += w - x + y + w;
        else if (dir==2)
            num += h - y + w - x + w + h;
        else
            num += x + h - y + 2 * w + h;
      
        dir = (num/(w+h))%2 * 2;
        int r = num %(w+h);
        if (r > w) 
            dir += 1;
        
        if (dir == 3) {x=0;y=h-r+w;} 
        else if (dir == 2) {x=w-r; y=h;}
        else if (dir == 1) {x=w; y=r-w;}
        else {x=r;y=0;}
		
        if (r==0)
            dir = dir==0?3:dir-1;
    }
    
    vector<int> getPos() 
    {
        return vector<int>({x,y});
    }
    
    string getDir() 
    {
        return dirstr[dir];
    }
};