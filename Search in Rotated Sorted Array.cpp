
class Solution {
public:
    int searchRec(int A[], int start, int end, int target)
    {
        if(start > end)
            return -1;
            
        int mid = start + (end - start)/2;
        if(A[mid] == target)
            return mid;
        if(A[start] <= A[mid])
        {
            if(target >= A[start] && target < A[mid])
                return searchRec(A,start,mid-1,target);
            else return searchRec(A,mid+1,end,target);
        }
        else 
        {
            if(target > A[mid] && target <= A[end])
                return searchRec(A,mid+1,end,target);
            else return searchRec(A,start,mid-1,target);
        
        }
    
    }
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return searchRec(A,0,n-1,target);
    }
};
