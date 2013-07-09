
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > vec(m+1,vector<int>(n+1));
        vec[0][0] = 0;
        for(int i = 1; i <= m; i++)
            vec[i][0] = i;
        for(int i = 1; i <= n; i++)
            vec[0][i] = i;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                if(word1[i-1] == word2[j-1])
                    vec[i][j] = vec[i-1][j-1];
                else vec[i][j] = min(vec[i-1][j-1],min(vec[i][j-1],vec[i-1][j])) + 1;
            
            }
        return vec[m][n];
    }
};