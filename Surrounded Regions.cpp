class Solution {
public:
    typedef pair<int,int> Pair;
    void traverseDFS(vector<vector<char> >& board, int row, int col, int m, int n, set<Pair>& hash)
    {
        if(row >= 0 && row < m && col >= 0 && col < n)
        {
            if(hash.count(Pair(row,col)))
                return;
            hash.insert(make_pair(row,col));
            if(board[row][col] == 'O')
            {
                board[row][col] = 'D';
                traverseDFS(board,row+1,col,m,n,hash);
                traverseDFS(board,row,col+1,m,n,hash);
                traverseDFS(board,row-1,col,m,n,hash);
                traverseDFS(board,row,col-1,m,n,hash);
            }    
        }
    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty())
            return;
        int m = board.size();
        int n = board[0].size();
        set<Pair> hash;
        for(int i = 0; i < n; i++)
        {
            traverseDFS(board,0,i,m,n,hash);
            traverseDFS(board,m-1,i,m,n,hash);
        }
        for(int i = 1; i < m-1; i++)
        {
            traverseDFS(board,i,0,m,n,hash);
            traverseDFS(board,i,n-1,m,n,hash);
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'D')
                    board[i][j] = 'O';
            }
    }
};

class Solution {
public:
    typedef pair<int,int> Pair;
    bool isValid(int row, int col, int m, int n)
    {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    void traverseBFS(vector<vector<char> >& board, int row, int col, int m, int n)
    {
        queue<Pair> que;
        que.push(Pair(row,col));
        board[row][col] = 'D';
        while(!que.empty())
        {
            Pair top = que.front();
            que.pop();
            int i = top.first;
            int j = top.second;
            board[i][j] = 'D';
            if(isValid(i+1,j,m,n) && board[i+1][j] == 'O')
                que.push(Pair(i+1,j));
            if(isValid(i,j+1,m,n) && board[i][j+1] == 'O')
                que.push(Pair(i,j+1));
            if(isValid(i-1,j,m,n) && board[i-1][j] == 'O')
                que.push(Pair(i-1,j));
            if(isValid(i,j-1,m,n) && board[i][j-1] == 'O')
                que.push(Pair(i,j-1));
        }
    
    
    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O')
                traverseBFS(board,0,i,m,n);
            if(board[m-1][i] == 'O')
                traverseBFS(board,m-1,i,m,n);
        }
        for(int i = 1; i < m-1; i++)
        {
            if(board[i][0] == 'O')
                traverseBFS(board,i,0,m,n);
            if(board[i][n-1] == 'O')
                traverseBFS(board,i,n-1,m,n);
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {   
                if(board[i][j] == 'O')
                    board[i][j] = 'X'; 
                if(board[i][j] == 'D')
                    board[i][j] = 'O';
            
            }
    }
};