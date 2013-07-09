

class Solution {
public:
    void swap(int A[], int i, int j)
    {
        int tem = A[i];
        A[i] = A[j];
        A[j] = tem;
    }
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        int pivpos = 0;
        for(int i = 1; i < n; i++)
            if(A[i] != A[pivpos])
                swap(A,++pivpos,i);
        return pivpos+1;
    }
};
