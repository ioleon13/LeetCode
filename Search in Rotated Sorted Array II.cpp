
class Solution {
public:
    bool searchRec(int A[], int start, int end, int target)
    {
        if(start > end)
            return false;
        int mid = start + (end-start)/2;
        if(A[mid] == target)
            return true;
        if(A[start] < A[mid])
        {
            if(target >= A[start] && target < A[mid])
                return searchRec(A,start,mid-1,target);
            else return searchRec(A,mid+1,end,target);
        }
        else if(A[start] > A[mid])
        {
            if(target > A[mid] && target <= A[end])
                return searchRec(A,mid+1,end,target);
            else return searchRec(A,start,mid-1,target);
        }
        else
        {
            if(A[start] != A[end])
                return searchRec(A,mid+1,end,target);
            else return searchRec(A,start,mid-1,target) || searchRec(A,mid+1,end,target);
        }
    
    }
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return searchRec(A,0,n-1,target);
    }
};