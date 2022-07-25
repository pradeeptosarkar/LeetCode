class NumberContainers {
public:
    
    unordered_map<int, set<int>> indlist;
    unordered_map<int, int> mp;
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) 
    {
        if(mp.count(index))
        {
            int temp=mp[index];
            indlist[temp].erase(index);
        }
        
        mp[index]=number;
        indlist[number].insert(index);   
    }
    
    int find(int number) 
    {
        if(indlist[number].size()==0)
            return -1;
        
        return *(indlist[number].begin());
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */