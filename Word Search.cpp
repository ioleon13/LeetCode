
class Solution {
public:
    typedef pair<int,int> Pair;
    bool existRec(vector<vector<char> >& board, string word, int pos, int row, int col, int m, int n, set<Pair>& hash)
    {
        if(pos == word.size())
            return true;
        if(row >= 0 && row < m && col >= 0 && col < n)
        {
            if(hash.count(Pair(row,col)))
                return false;
            if(board[row][col] != word[pos])
                return false;
            hash.insert(make_pair(row,col));
            return existRec(board,word,pos+1,row,col-1,m,n,hash) || existRec(board,word,pos+1,row,col+1,m,n,hash) || existRec(board,word,pos+1,row-1,col,m,n,hash) || existRec(board,word,pos+1,row+1,col,m,n,hash);
        }
        else return false;
    
    
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i < m; i++)
            for(int j = 0; j < n; j++)
            {
                set<Pair> hash;
                if(existRec(board,word,0,i,j,m,n,hash))
                    return true;  
            }
        return false;
        
    }
};
