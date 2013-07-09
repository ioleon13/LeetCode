
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> rowSet;
        set<int> colSet;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                {
                    rowSet.insert(i);
                    colSet.insert(j);
                }
         for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(rowSet.count(i) || colSet.count(j))
                    matrix[i][j] = 0;
            }
        
    }
};


class Solution {
public:
    void setRowZero(vector<vector<int> >& matrix, int row, int n)
    {
        for(int i = 0; i < n; i++)
            matrix[row][i] = 0;
    }
    void setColZero(vector<vector<int> >& matrix, int col, int m)
    {
        for(int i = 0; i < m; i++)
            matrix[i][col] = 0;
    }
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool row = false;
        bool col = false;
        for(int i = 0; i < m; i++)
            if(matrix[i][0] == 0)
            {
                col = true;
                break;
            }
        for(int i = 0; i < n; i++)
            if(matrix[0][i] == 0)
            {
                row = true;
                break;
            }
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for(int i = 1; i < m; i++)
            if(matrix[i][0] == 0)
                setRowZero(matrix,i,n);
        for(int i = 1; i < n; i++)
            if(matrix[0][i] == 0)
                setColZero(matrix,i,m);
        if(row)
            setRowZero(matrix,0,n);
        if(col)
            setColZero(matrix,0,m);
    }
};
