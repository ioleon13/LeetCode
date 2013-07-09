
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int m = s1.size();
        int n = s2.size();
        if(s3.size() != m + n)
            return false;
        vector<vector<int> > vec(m+1,vector<int>(n+1));
        vec[0][0] = 1;
        for(int i = 1; i <= m; i++)
            if(s1[i-1] == s3[i-1])
                vec[i][0] = 1;
            else break;
        for(int i = 1; i <= n; i++)
            if(s2[i-1] == s3[i-1])
                vec[0][i] = 1;
            else break;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                vec[i][j] = (s3[i+j-1] == s1[i-1] && vec[i-1][j]) || (s3[i+j-1] == s2[j-1] && vec[i][j-1]);
        return vec[m][n];
    }
};
