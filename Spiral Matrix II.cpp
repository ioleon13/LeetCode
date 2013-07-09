
class Solution {
public:
    void generateRec(vector<vector<int> >& matrix, int start, int len, int item)
    {
        if(len <= 0)
            return;
        if(len == 1)
        {
            matrix[start][start] = item;
            return ;
        }
        for(int i = start; i < start+len-1; i++,item++)
            matrix[start][i] = item;
        for(int i = start; i < start+len-1; i++, item++)
            matrix[i][start+len-1] = item;
        for(int i = start+len-1; i > start; i--,item++)
            matrix[start+len-1][i] = item;
        for(int i = start+len-1; i > start; i--,item++)
            matrix[i][start] = item;
        generateRec(matrix,start+1,len-2,item);
    
    }
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return vector<vector<int> >();
        vector<vector<int> > matrix(n,vector<int>(n));
        generateRec(matrix,0,n,1);
        return matrix;
    }
};