
class Solution {
public:
    void traverseRec(vector<vector<int> >& matrix, int row, int col, int start, vector<int>& ret, int m, int n)
    {
        if(row <= 0 || col <= 0)
            return;
        if(row == 1 && col > 0)
        {
            for(int i = start; i <= start+col-1; i++)
                ret.push_back(matrix[i][start]);
            return;
        }
        if(col == 1 && row > 0)
        {
            for(int i = start; i <= start+row-1; i++)
                ret.push_back(matrix[start][i]);
            return;
        }
        for(int i = start; i < start+row-1; i++)
            ret.push_back(matrix[start][i]);
        for(int i = start; i < start+col-1; i++)
            ret.push_back(matrix[i][start+row-1]);
        for(int i = start+row-1; i > start; i--)
            ret.push_back(matrix[start+col-1][i]);
        for(int i = start+col-1; i > start; i--)
            ret.push_back(matrix[i][start]);
        traverseRec(matrix,row-2,col-2,start+1,ret,m,n);
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(matrix.empty())
            return ret;
        int m = matrix.size();
        int n = matrix[0].size();
        traverseRec(matrix,n,m,0,ret,m,n);
        return ret;
    }
};
