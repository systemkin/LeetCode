//We have vector of prices of something
//Found best date for buy and sell. (1 buy date 1 sell)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int min = prices[0];
        for(int i = 1; i < prices.size(); i++)
            if ((prices[i] - min) > result)
                result = prices[i] - min;
            else if (prices[i] < min)
                min = prices[i];
        return result;
    }
};
