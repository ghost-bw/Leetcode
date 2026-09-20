class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int fmin=INT_MAX,smin=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<fmin){
                smin=fmin;
                fmin=prices[i];
            }else{
                smin=min(smin,prices[i]);
            }
        }
        if(fmin+smin<=money){
            money-=(fmin+smin);
        }
        return money;
    }
};