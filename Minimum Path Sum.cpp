
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vec(m,INT_MAX);
        vec[m-1] = 0;
        for(int j = n-1; j >= 0; j--)
            for(int i = m-1; i >= 0; i--)
            {
                int downVal = i+1 < m ? vec[i+1] : INT_MAX;
                vec[i] = min(vec[i],downVal) + grid[i][j];
            }
        return vec[0];
    }
};