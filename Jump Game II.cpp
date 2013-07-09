
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        if(n == 1)
            return 0;
        int maxRange = A[0];
        int step = 1;
        int start = 1;
        while(maxRange < n-1)
        {
            int newRange = maxRange;
            for(int i = start; i <= maxRange; i++)
                if(A[i] + i > newRange)
                    newRange = A[i] + i;
            start = maxRange + 1;
            maxRange = newRange;
            step++;
        }
        return step;
    }
};