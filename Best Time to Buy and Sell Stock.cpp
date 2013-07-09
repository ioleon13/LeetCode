class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.empty())
            return 0;
        int n = prices.size();
        int maxval = 0;
        int maxEnd = 0;
        for(int i = 0; i < n-1; i++)
        {
            int profit = prices[i+1] - prices[i];
            maxEnd = max(0,profit + maxEnd);
            maxval = max(maxEnd,maxval);
        }
        return maxval ;
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.empty())
            return 0;
        int n= prices.size();
        int minVal = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < n; i++)
        {
            maxProfit = max(prices[i]-minVal,maxProfit);
            minVal = min(minVal,prices[i]);
        }
        return maxProfit;
    }
};
