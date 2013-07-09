
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n-1;
        while(row < m && col >= 0)
        {
            if(matrix[row][col] < target)
                row++;
            else if(matrix[row][col] > target)
                col--;
            else return true;
        
        }
        return false;
    }
};
