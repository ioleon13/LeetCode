
class Solution {
public:
    void swap(int A[], int i, int j)
    {
        int tem = A[i];
        A[i] = A[j];
        A[j] = tem;
    }
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        int pivpos = -1;
        for(int i = 0; i < n; i++)
            if(A[i] != elem)
                swap(A,++pivpos,i);
        return pivpos+1;
    }
};
