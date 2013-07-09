
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.empty())
            return 0;
        int n = prices.size();
        int ret = 0;
        for(int i = 1; i < n; i++)
        {
            int profit = prices[i] - prices[i-1];
            if(profit > 0)
                ret += profit;
        }
        return ret;
        
    }
};