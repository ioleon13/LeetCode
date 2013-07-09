
class Solution {
public:
    void searchRec(int A[], int start, int end, int target, vector<int>& vec)
    {
        if(start > end)
            return;
        int mid = start + (end - start) / 2;
        if(A[mid] == target)
        {
            int i = mid;
            int j = mid;
            while(i >= start && A[i] == target)
                i--;
            while(j <= end && A[j] == target)
                j++;
            vec[0] = i+1;
            vec[1] = j-1;
        
        }
        else if (A[mid] > target)
            return searchRec(A,start,mid-1,target,vec);
        else return searchRec(A,mid+1,end,target,vec);
            
        
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec(2,-1);
        searchRec(A,0,n-1,target,vec);
        return vec;
    }
};

