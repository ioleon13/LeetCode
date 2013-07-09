
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        vector<int> leftVec(n);
        vector<int> rightVec(n);
        leftVec[0] = A[0];
        rightVec[n-1] = A[n-1];
        int maxval = A[0];
        for(int i = 1; i < n; i++)
        {
            leftVec[i] = maxval;
            if(A[i] > maxval)
                maxval = A[i];
        }
        maxval = A[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            rightVec[i] = maxval;
            if(A[i] > maxval)
                maxval = A[i];
        }
        int ret = 0;
        for(int i = 1; i < n-1; i++)
        {
            int candi = min(leftVec[i],rightVec[i]) - A[i];
            if(candi > 0)
                ret += candi;
        }
        return ret;
    }
};