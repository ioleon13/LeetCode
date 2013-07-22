//DP
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

//scan
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


//divide and conquer
class Solution {
public:
    int findMaxDif(vector<int>& prices, int start, int end, int& minVal, int& maxVal)
    {
        if(start == end)
        {
            minVal = prices[start];
            maxVal = prices[start];
            return 0;
        }
        int mid = start + (end - start) / 2;
        int leftMin;
        int leftMax;
        int leftDif = findMaxDif(prices,start,mid,leftMin,leftMax);
        int rightMin;
        int rightMax;
        int rightDif = findMaxDif(prices,mid+1,end,rightMin,rightMax);
        minVal = min(leftMin,rightMin);
        maxVal = max(leftMax,rightMax);
        return max(rightMax-leftMin,max(leftDif,rightDif));
    }
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.empty())
            return 0;
        int n = prices.size();
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        return findMaxDif(prices,0,n-1,minVal,maxVal);
    }
};