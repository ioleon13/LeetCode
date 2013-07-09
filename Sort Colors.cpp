
class Solution {
public:
    void swap(int A[], int i, int j)
    {    
        int tem = A[i];
        A[i] = A[j];
        A[j] = tem;
    }
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = -1;
        int j = n;
        int current = 0;
        while(current < j)
        {
            if(A[current] == 0)
            {
                swap(A,++i,current);
                current++;
            }
            else if(A[current] == 1)
                current++;
            else if(A[current] == 2)
                swap(A,--j,current);
        }
    }
};
