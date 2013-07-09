
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        int maxRange = A[0];
        for(int i = 1; i <= maxRange; i++)
        {
            int candi = A[i] + i;
            if(candi > maxRange)
                maxRange = candi;
            if(maxRange >= n-1)
                return true;
        }
        return false;
    }
};
