
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.empty())
            return 0;
        int n = prices.size();
        vector<int> left(n);
        vector<int> right(n);
        int minVal = prices[0];
        left[0] = 0;
        right[n-1] = 0;
        for(int i = 1; i < n; i++)
        {
            left[i] = max(left[i-1],prices[i]-minVal);
            minVal = min(minVal,prices[i]);
        }
        int maxVal = prices[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            right[i] = max(right[i+1],maxVal-prices[i]);
            maxVal = max(maxVal,prices[i]);
        }
        int ret = 0;
        for(int i = 0; i < n; i++)
            ret = max(ret,left[i]+right[i]);
        
        return ret;
        
        
    }
};