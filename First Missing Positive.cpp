
class Solution {
public:
    void swap(int A[], int i, int j)
    {
        int tem = A[i];
        A[i] = A[j];
        A[j] = tem;
    }
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 1;
        int pivpos = -1;
        for(int i = 0; i < n; i++)
            if(A[i] > 0)
                swap(A,++pivpos,i);
        for(int i = 0; i <= pivpos; i++)
        {
            int idx = abs(A[i]) - 1;
            if(idx <= pivpos && A[idx] > 0)
                A[idx] = -A[idx];
        }        
        for(int i = 0; i <= pivpos; i++)
            if(A[i] > 0)
                return i+1;
        return pivpos+2; 
    }
};