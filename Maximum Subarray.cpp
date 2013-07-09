
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxEnd = A[0];
        int maxval = A[0];
        for(int i = 1; i < n; i++)
        {
            maxEnd = max(A[i],A[i] + maxEnd);
            maxval = max(maxEnd,maxval);
        }
        return maxval;
    }
};
