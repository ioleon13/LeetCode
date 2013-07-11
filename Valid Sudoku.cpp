class Solution {
public:
    const int dim = 3;
    bool isRowValid(vector<char>& row, int n)
    {
        set<char> hash;
        for(int i = 0; i < n; i++)
            if(row[i] != '.')
            {
                if(hash.count(row[i]))
                    return false;
                else hash.insert(row[i]);
            }
        return true;
    }
    bool isColValid(vector<vector<char> >& board, int m, int n)
    {
        
        for(int i = 0; i < n; i++)
        {
            set<char> hash;
            for(int j = 0; j < m; j++)
                if(board[j][i] != '.')
                {
                    if(hash.count(board[j][i]))
                        return false;
                    else hash.insert(board[j][i]);
                }
        }       
        return true;
    }
    bool isGridValid(vector<vector<char> >& board, int startX, int startY)
    {
        set<char> hash;
        for(int i = 0; i < dim; i++)
            for(int j = 0; j < dim; j++)
            {
                int x = startX + i;
                int y = startY + j;
                if(board[x][y] != '.')
                {
                    if(hash.count(board[x][y]))
                        return false;
                    hash.insert(board[x][y]);
                }
            
            }
        return true;
            
    
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        assert(m == n);
        for(int i = 0; i < m; i++)
            if(!isRowValid(board[i],n))
                return false;
        
        if(!isColValid(board,m,n))
            return false;
        
        for(int i = 0; i < m/dim; i++)
            for(int j = 0; j < n/dim; j++)
            {
                int startX = i*dim;
                int startY = j*dim;
                if(!isGridValid(board,startX,startY))
                    return false;
            }
        return true;
    }
};
