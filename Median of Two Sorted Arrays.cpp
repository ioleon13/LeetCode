
class Solution {
public:
    int findKSmallest(int A[], int m, int B[], int n, int k)
    {
    
        if(m <= 0)
            return B[k-1];
        if(n <= 0)
            return A[k-1];
        int i = (double)m/(m+n)*k - 1;
        int j = k - i - 1;
        int Ai_1 = i == 0 ? INT_MIN : A[i-1];
        int Bj_1 = j == 0 ? INT_MIN : B[j-1];
        int Ai = i == m ? INT_MAX : A[i];
        int Bj = j == n ? INT_MAX : B[j];
        
        if(Ai >= Bj_1 && Ai <= Bj)
            return Ai;
        if(Bj >= Ai_1 && Bj <= Ai)
            return Bj;
            
        if(Ai < Bj)
            return findKSmallest(A+i+1,m-i-1,B,j,k-i-1);
        else return findKSmallest(A,i,B+j+1,n-j-1,k-j-1);
    
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if((m+n)%2 != 0)
            return findKSmallest(A,m,B,n,(m+n)/2+1);
        else
        {
            double first = findKSmallest(A,m,B,n,(m+n)/2);
            double second = findKSmallest(A,m,B,n,(m+n)/2+1);
            return (first+second)/2;
        }
    }
};