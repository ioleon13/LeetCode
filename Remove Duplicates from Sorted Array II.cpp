
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        int pivpos = 0;
        bool once = false;
        for(int i = 1; i < n; i++)
        {
            if(A[i] == A[pivpos] && !once)
            {
                once = true;
                A[++pivpos] = A[i];
            }
            if(A[i] != A[pivpos])
            {
                once = false;
                A[++pivpos] = A[i];
            }
        }
        return pivpos+1;
    }
};