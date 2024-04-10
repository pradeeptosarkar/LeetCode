class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int count=0;
        int i=0;
        int size=tickets.size();
        while(1){
            if(tickets[i] > 0){
                count++;
            }
            tickets[i]--;
            if(tickets[k]==0){
                return count;
            }
            i=(i+1)%size;
        }
    }
};
