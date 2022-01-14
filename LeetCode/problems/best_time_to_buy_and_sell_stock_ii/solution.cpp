class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)
            return 0;
        int price=prices[0],profet=0;
        for(int i=1;i<prices.size();i++){
            price=min(price,prices[i]);
            if(prices[i]>price){
                profet+=prices[i]-price;
                price=prices[i];
            }
        }
        return profet;
    }
};