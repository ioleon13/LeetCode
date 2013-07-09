

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.empty())
            return 0;
        int n = height.size();
        vector<int> leftVec(n);
        vector<int> rightVec(n);
        leftVec[0] = 0;
        rightVec[n-1] = n-1;
        
        for(int i = 1; i < n; i++)
        {
            int j = i;
            while(j-1 >= 0 && height[i] <= height[j-1])
                j = leftVec[j-1];
            leftVec[i] = j;
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            int j = i;
            while(j+1 < n && height[i] <= height[j+1])
                j = rightVec[j+1];
            rightVec[i] = j;
        
        }
        int maxval = 0;
        for(int i = 0; i < n; i++)
        {    
            int candi = (rightVec[i] - leftVec[i] + 1) * height[i];
            if(candi > maxval)
                maxval = candi;
        }
        return maxval;
    }
};