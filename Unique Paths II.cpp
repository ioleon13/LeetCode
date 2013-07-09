
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > vec(m,vector<int>(n));
        for(int i = n-1; i >= 0; i--)
            if(obstacleGrid[m-1][i] == 0)
                vec[m-1][i] = 1;
            else break;
        for(int i = m-1; i >= 0; i--)
            if(obstacleGrid[i][n-1] == 0)
                vec[i][n-1] = 1;
            else break;
        for(int i = m-2; i >= 0; i--)
            for(int j = n-2; j >= 0; j--)
            {
                if(!obstacleGrid[i][j])
                    vec[i][j] = !obstacleGrid[i][j+1]*vec[i][j+1] + !obstacleGrid[i+1][j]*vec[i+1][j];
                else vec[i][j] = 0;
            
            }
        return vec[0][0];
    }
};
