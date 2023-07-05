class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int maxProfit = INT_MIN;

        for(int i=0;i<prices.size();i++){
            if(min >= prices[i]){
                min = prices[i];
                
            }
            maxProfit = max(maxProfit,prices[i] - min);
        }
        return maxProfit;
    }
};